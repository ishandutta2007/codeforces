#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll big = 1000000007ll;
const ll big2 = 1000000009ll;
ll n,m,k,q,w,h,T;

ll inf = -big;

template <class T>
struct RMQ {
	vector<vector<T>> jmp;

	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < sz(V)) on *= 2, depth++;
		//jmp.assign(depth, V);

		for(ll c1 = 0; c1 < depth+1; c1++){
            vector<T> temp;
            for(ll c2 =0 ; c2 < N; c2++)temp.push_back(0);
            jmp.push_back(temp);
		}

		for(ll c1 = 0; c1 < N; c1++){
            jmp[0][c1] = V[c1];
		}

		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = max(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}

	T query(int a, int b) {
		if (b <= a) return inf;
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

vector<int> D;
vector<int> D2;
vector<ll> A;
vector<ll> ind;

ll ANS[100001] = {0};

bool comp(ll i, ll j){
    return A[i] < A[j];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n;
    //n = 3;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> a;
       // a = rand()%5000;
        A.push_back(a);
        ind.push_back(c1);
    }

    sort(all(ind),comp);
    D.push_back(100000*A[ind[0]]);
    D2.push_back(A[ind[0]]);
    for(ll c1 = 1; c1 < n; c1++){
        D.push_back((A[ind[c1]]-A[ind[c1-1]]) * 100000 + c1);
        D2.push_back(A[ind[c1]]-A[ind[c1-1]]);
    }
    RMQ<int> rmq(D);
/*
    for(ll c1 = 0; c1 < n; c1++){
        cout << D[c1] << " ";
    }cout << "\n";
*/
    ll ans = -1;
    ll a1 = 0;
    ll a2 = 0;
    ll a3 = 0;

    for(ll c1 = 0; c1 < n; c1++){
        for(ll c2 = c1+1; c2 < n; c2++){
            ll l1 = c2-c1;
            ll l2 = n-c2;

            ll mil = min(l1,l2);
            ll mal = max(l1,l2);

            if(mal > 2*mil)continue;

            ll mil2 = (mal+1)/2;
            ll mal2 = 2*mil;


            ll l = max((c1-mal2),0ll);
            ll r = max((c1-mil2+1),0ll);

            ll c3 = rmq.query(l,r);

           // cout << c1 << " " << c2 << "  l1: " << l1 << "  l2: " << l2 << "   mil: " << mil << "  mal: " << mal;
           // cout <<  "   [" << l << " " << r << ")     " << c3 << "\n";

            if(c3 != inf){
                ll i1 = c1;
                ll i2 = c2;
                ll i3 = c3%100000;

                //cout << i3 << " " << i1 << " "<<i2 << "\n";

                ll h = ll(10000000000)*ll(D2[c2])+100000*D2[c1]+c3/100000;

                if(h > ans){
                    ans = h;
                    a1 = i1;
                    a2 = i2;
                    a3 = i3;
                   // cout << a3 << " " << a1 << " " << a2 << "   " << h <<"\n";
                }

            }

        }
    }

    for(ll c1 =0 ; c1 < n; c1++){
        if(c1 < a3){
            ANS[ind[c1]] = -1;
        }
        else{
            if(c1 < a1){
                ANS[ind[c1]] = 3;
            }
            else{
                if(c1 < a2){
                    ANS[ind[c1]] = 2;
                }
                else{
                    ANS[ind[c1]] = 1;
                }
            }
        }
    }

    for(ll c1 = 0; c1 < n; c1++){
        cout << ANS[c1] << " ";
    }

    return 0;
}
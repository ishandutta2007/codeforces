#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<double,double> pdd;

vector<int> match;
vector<bool> seen;
template<class G>
bool find(int j, G &g) {
	if (match[j] == -1) return 1;
	seen[j] = 1; int di = match[j];
	trav(e, g[di])
		if (!seen[e] && find(e, g)) {
			match[e] = di;
			match[j] = -1;
			return 1;
		}
	return 0;
}
template<class G>
int dfs_matching(G &g, int n, int m) {
	match.assign(m, -1);
	rep(i,0,n) {
		seen.assign(m, false);
		trav(j,g[i])
			if (find(j, g)) {
				match[j] = i;
				break;
			}
	}
	return m - count(all(match), -1);
}

const ll big = 1000000007;
const ll mod = 998244353;

vector<vi> C(12300, vi());

ll n,m,k,q,T;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
   // freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> m;
    if(n > m)swap(n,m);
    ll area = n*m;

    if(n%6 == 0 || m%6 == 0){
        cout << area << "\n";
        return 0;
    }
    if(n >= 20 && m >= 20){
        cout << area-area%2 << "\n";
        return 0;
    }
    if(n <= 40 && m <= 40){
        ll i = 0;
        ll rig = 0;
        for(int c1 = 0; c1 < n; c1++){
            for(int c2 = 0; c2 < m; c2++){

                ll par = (c1+c2)%2;
                if(par == 1)continue;
                ll j = 0;
                for(int c3 = 0; c3 < n; c3++){
                    for(int c4 = 0; c4 < m; c4++){

                        ll dist = abs(c1-c3)+abs(c2-c4);
                        if(dist == 3){
                            C[i].push_back(j);
                        }
                        if((c3+c4)%2 == 1){
                            j++;
                        }
                    }
                }
                rig = j;
                i++;
            }
        }

        cout << 2*dfs_matching(C,i,rig) << "\n";
        return 0;
    }


    if(n == 1){
        ll extra = 0;
        if(m%6 == 1)extra = 1;
        if(m%6 == 2)extra = 2;
        if(m%6 == 3)extra = 3;
        if(m%6 == 4)extra = 2;
        if(m%6 == 5)extra = 1;
        cout << area-extra << "\n";
        return 0;
    }
/*
    if(n == 2){
        if(m%4 == 0 || m%5 == 0 || m%6 == 0 || m >= 10){
            cout << area << "\n";
            return 0;
        }
        if(m == 3){
            cout << 4 << "\n";
            return 0;
        }
        if(m == )
    }
*/


    cout << area-area%2 << "\n";

    return 0;
}
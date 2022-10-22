#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

#define rep(i,a,b) for(int i = a;i<(b);++i)
#define trav(a,v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
int n,m,k,q,w,h,x,y;

vector<int> A;
vector<vector<int> > P(1000001, vector<int>());

vector<int> A2;
vector<int> D;

vector<int> prime;

bool markp[1000001] = {0};

int F[1000001] = {0};

ll gcd(ll i, ll j){
    if(j == 0)return i;
    return gcd(j,i%j);
}

ll eva(ll p){
    ll miy = big*big;
    ll ans = 0;
    bool nox = 1;
    for(ll c1 = 0; c1 < n; c1++){
        ll ycost = ll(D[c1])*ll(y)*ll((p-A2[c1]%p)%p);
        ll ycost2 = ll(y)*ll((p-A2[c1]%p)%p);
        ll xcost = ll(D[c1])*ll(x);
        if(ycost2 < miy){
            miy = ycost2;
        }
        if(ycost <= xcost)nox = 0;
        ans += min(ycost,xcost);
    }
    //if(nox)ans += miy-x;
    return ans;
}

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,d,e;

    for(ll c1 = 2; c1 < 1000001; c1++){
        if(!markp[c1]){
            P[c1].push_back(c1);
            prime.push_back(c1);
            for(ll c2 = c1+c1; c2 < 1000001; c2 += c1){
                markp[c2] = 1;
                P[c2].push_back(c1);
            }
        }
    }

    scanf("%d", &n);
    scanf("%d", &x);
    scanf("%d", &y);
    ll g = 0;
    for(ll c1 = 0; c1 < n; c1++){
        scanf("%d", &a);
        if(c1 == 0){
            g = a;
        }
        else{
            g = gcd(g,a);
        }
        A.push_back(ll(a));
    }

    if(g != 1){
        cout << "0\n";
    }
    else{
        sort(all(A));
        ll prev = -1;
        for(ll c1 = 0; c1 < n; c1++){
            if(A[c1] == prev){
                D[sz(A2)-1]++;
            }
            else{
                A2.push_back(A[c1]);
                D.push_back(1);
            }
        }
        ll n2 = n;
        n = sz(A2);
        for(ll c1 = 0; c1 < n; c1++){
            a = A2[c1];
            for(ll c2 = 0; c2 < sz(P[a]); c2++){
                F[P[a][c2]] += D[c1];
            }
        }

        ll ans = eva(2);

        for(ll c1 = 0; c1 < sz(prime); c1++){
            int p = prime[c1];
            ll notdiv = ll(n2-F[p]);
            if(notdiv*ll(min(x,y)) < ans){
                ans = min(ans,eva(p));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
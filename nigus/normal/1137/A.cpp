#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,q;
const ll big = 1000000007;
const ll MAXN = 150000;

ll M[1001][1001] = {0};
ll MM[1001][1001][2] = {0};
ll MMAX[1001][2] = {0};

vl A;
vl ind;

bool comp(ll i, ll j){
    return A[i] < A[j];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m;

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            cin >> a;
            M[c1][c2] = a;
        }
    }

    for(int c2 = 0; c2 < m; c2++){
        A.clear();
        ind.clear();
        for(int c1 = 0; c1 < n; c1++){
            ind.push_back(c1);
            A.push_back(M[c1][c2]);
        }
        sort(all(ind),comp);
        ll prev = -1;
        ll now = 0;
        for(int c1 = 0; c1 < n; c1++){
            if(A[ind[c1]] != prev){
                now++;
            }
            MM[ind[c1]][c2][0] = now;
            prev = A[ind[c1]];
        }
        MMAX[c2][0] = now;
    }

    for(int c2 = 0; c2 < n; c2++){
        A.clear();
        ind.clear();
        for(int c1 = 0; c1 < m; c1++){
            ind.push_back(c1);
            A.push_back(M[c2][c1]);
        }
        sort(all(ind),comp);
        ll prev = -1;
        ll now = 0;
        for(int c1 = 0; c1 < m; c1++){
            if(A[ind[c1]] != prev){
                now++;
            }
            MM[c2][ind[c1]][1] = now;
            prev = A[ind[c1]];
        }
        MMAX[c2][1] = now;
    }

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < m; c2++){
            ll ans1 = MMAX[c1][1];
            ll ans2 = MMAX[c2][0];
            if(MM[c1][c2][0] > MM[c1][c2][1]){
                ans1 += MM[c1][c2][0] - MM[c1][c2][1];
            }
            else{
                ans2 -= MM[c1][c2][0] - MM[c1][c2][1];
            }
            cout << max(ans1,ans2) << " ";
        }
        cout << "\n";
    }


    return 0;
}
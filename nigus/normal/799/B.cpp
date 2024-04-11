#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
int n,m,T,k;
int c,d;

vector<vector<ll> > C(9 , vector<ll>());

vector<ll> P;
vector<ll> A;
vector<ll> B;
vector<ll> M;
vector<ll> L;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b;

    scanf("%d" , &n);
    for(ll c1 = 0; c1 < n; c1++){
        scanf("%d" , &a);
        P.push_back(a);
    }
    for(ll c1 = 0; c1 < n; c1++){
        scanf("%d" , &a);
        A.push_back(a-1);
    }
    for(ll c1 = 0; c1 < n; c1++){
        scanf("%d" , &a);
        B.push_back(a-1);
    }

    for(ll c1 = 0; c1 < n; c1++){
        C[A[c1]*3+B[c1]].push_back(P[c1]);
    }


    for(ll c1 = 0; c1 < 9; c1++){
        sort(all(C[c1]));
        L.push_back(0);
    }

    scanf("%d" , &m);
    for(ll c1 = 0; c1 < m; c1++){
        scanf("%d" , &a);
        a--;
        ll ans = big;
        ll choice = -1;
        for(ll c2 = 0; c2 < 9; c2++){
            if(c2/3 == a || c2%3 == a){
                if(L[c2] != C[c2].size()){
                    if(C[c2][L[c2]] < ans){
                        ans = C[c2][L[c2]];
                        choice = c2;
                    }
                }
            }
        }

        if(choice != -1){
            L[choice]++;
            cout << ans << " ";
        }
        else{
            cout << -1 << " ";
        }

    }

    return 0;
}
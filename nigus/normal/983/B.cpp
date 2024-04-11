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
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

int n,m,q,p;
int T;

vi A;
int B[5001][5001] = {0};
int ANS[5001][5001] = {0};

int main() {

   // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    int a,b,c,e;

    scanf("%d", &n);
   // n = 5000;
    for(int c1 = 0; c1 < n; c1++){
        scanf("%d", &a);
       // a = (1 << 30)-1;
        A.push_back(a);
    }

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < n; c2++){
            ANS[c1][c2] = -1;
        }
    }

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < n-c1; c2++){
            if(c1 == 0){
                B[c2][c1] = A[c2];
            }
            else{
                B[c2][c1] = (B[c2][c1-1]^B[c2+1][c1-1]);
            }
        }
    }

    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < n-c1; c2++){
            if(c1 == 0){
                ANS[c2][c1] = B[c2][c1];
            }
            else{
                ANS[c2][c1] = max(max(ANS[c2][c1-1], ANS[c2+1][c1-1]), B[c2][c1]);
            }
        }
    }


    scanf("%d", &q);
   // q = 100000;
    for(int c1 = 0; c1 < q; c1++){
        scanf("%d", &a);
        scanf("%d", &b);
       // a = 1;
       // b = n;
        a--;
        b--;
        printf("%d\n",ANS[a][b-a]);
    }

    return 0;
}
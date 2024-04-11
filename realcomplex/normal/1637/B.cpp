#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
int dp[N][N];
int A[N];
int C[N];

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i ++ ){
            cin >> A[i];
        }
        for(int li = 1; li <= n; li ++ ){
            for(int ri = 1; ri <= n; ri ++ ){
                dp[li][ri] = 0;
            }
        }
        int ri;
        int mex;
        int res = 0;
        for(int sz = 1; sz <= n; sz ++ ){
            for(int li = 1; li + sz - 1 <= n; li ++ ){
                ri = li + sz - 1;
                for(int j = 0 ; j <= n + 2; j ++ ){
                    C[j] = 0;
                }
                for(int id = li; id <= ri ; id ++ ){
                    if(A[id] <= n)
                        C[A[id]] ++ ;
                }
                mex = 0;
                while(C[mex] > 0) mex ++ ;
                dp[li][ri] = mex + 1;
                for(int mid = li; mid < ri ; mid ++ ){
                    dp[li][ri] = max(dp[li][ri],dp[li][mid] + dp[mid+1][ri]);
                }
                res += dp[li][ri];
            }
        }
        cout << res << "\n";
    }
    return 0;
}
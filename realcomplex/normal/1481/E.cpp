#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 100;
int A[N];
int pf[N];
int sf[N];
int cnt[N];
int dp[N];
int las[N];
int tot[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        if(pf[A[i]] == 0){
            pf[A[i]] = i;
        }
        sf[A[i]] = i;
    }
    for(int i = n; i >= 1; i -- ){
        tot[A[i]]++ ;
        cnt[i]=tot[A[i]];

    }
    for(int i = 1; i <= n; i ++ ){
        if(sf[A[i]] == i){
            dp[i]=dp[pf[A[i]] - 1] + tot[A[i]];
        }
        dp[i]=max(dp[i],dp[i-1]);
    }
    int mx = dp[n];
    for(int i = n; i >= 1; i -- ){
        mx = max(mx, dp[i-1]+cnt[i]);
    }
    cout << n - mx << "\n";
    return 0;
}
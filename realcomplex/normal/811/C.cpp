#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define abs(a) ((a<0) ? -a : a)
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int N = 5009;
int left_oc[N],right_oc[N];
int has[N];
int arr[N];
int dp[N];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&arr[i]);
        right_oc[arr[i]]=i;
    }
    for(int i = n;i>=1;i--)
        left_oc[arr[i]]=i;
    int req_posl,req_posr;
    int current = 0;
    for(int i = 1;i<=n;i++){
        dp[i]=dp[i-1];
        req_posl=left_oc[arr[i]],req_posr=right_oc[arr[i]];
        for(int i = 0;i<N;i++)
            has[i]=0;
        current = 0;
        for(int j = i;j>0;j--){
            req_posl=min(req_posl,left_oc[arr[j]]);
            req_posr=max(req_posr,right_oc[arr[j]]);
            if(has[arr[j]]==0)
                has[arr[j]]=1,current^=arr[j];
            if(j<=req_posl and i>=req_posr){
                dp[i]=max(dp[i],dp[j-1]+current);
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
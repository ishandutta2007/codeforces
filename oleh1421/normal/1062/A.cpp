#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
int a[10001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    a[0]=0;
    for (int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=1001;
    int res=0;
    for (int i=0;i<=n+1;i++){
        for (int j=i+2;j<=n+1;j++){
            if (j-i-1==a[j]-a[i]-1){
                res=max(res,j-i-1);
            }
        }
    }
    cout<<res;
    return 0;
}
/*
35 1
1 2 3 4 5 6 7  8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
*/
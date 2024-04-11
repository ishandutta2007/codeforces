#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
double a[200001];
int ans[200001];
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int sum=0;
    for (int i=1;i<=n;i++) {
        ans[i]=floor(a[i]);
        sum+=ans[i];
    }
    for (int i=1;i<=n && sum<0;i++){
        if (abs(a[i]-ans[i]*1.0)>0.000001) {
            ans[i]++;
            sum++;
        }
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<endl;
    return 0;
}
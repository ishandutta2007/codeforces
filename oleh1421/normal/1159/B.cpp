#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[300001];
int main()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int cnt=0;
    int i=1;
    int j=n;
    int res=1000000001;
    int minx=min(a[1],a[n]);
    for (int t=n-1;t>=1;t--){
        res=min(res,minx/t);
        minx=min(minx,a[i+1]);
        minx=min(minx,a[j-1]);
        i++;
        j--;
    }
    cout<<res;
    return 0;
}
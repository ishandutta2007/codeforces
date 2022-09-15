#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if (a[n]>=a[n-1]+a[n-2]){
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    swap(a[n-1],a[n]);
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}
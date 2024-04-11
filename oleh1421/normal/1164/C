#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int q[1000001];
int a[1000001];
bool used[3000001];
int main()
{
    int m;cin>>m;
    for (int i=1;i<=m;i++) cin>>q[i];
    sort(q+1,q+m+1);
    int qq=q[1];
    int n;cin>>n;
    for (int j=1;j<=n;j++) cin>>a[j];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int last=0;
    while(last<n){
        last+=qq;
        used[last+1]=true;
        used[last+2]=true;
        last+=2;
    }
    int res=0;
    for (int i=1;i<=n;i++){
        if (used[i]) continue;
        res+=a[i];
    }
    cout<<res;
    return 0;
}
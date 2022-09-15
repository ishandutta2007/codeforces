#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[100002];
int main()
{
    int t;cin>>t;
    while (t--){
        int n,d,x,y;cin>>n>>x>>y>>d;
        int res=2000000001;
        if (abs(x-y)%d==0) res=min(res,abs(x-y)/d);
        if (y%d==1) res=min(res,(x-1)/d+((x-1)%d>0)+(y-1)/d);
        if (y%d==n%d) res=min(res,(n-x)/d+((n-x)%d>0)+(n-y)/d);
        if (res==2000000001) cout<<-1<<endl;
        else cout<<res<<endl;
    }
   return 0;
}
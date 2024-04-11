#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//int a[500001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b,x,y,n;cin>>a>>b>>x>>y>>n;
    if (x>y){
        swap(a,b);
        swap(x,y);
    }
    int m1=min(n/x,a);
    int maxx=m1+(n-m1*x)/y;
    n-=a*(x-1)+b*(y-1);
    cout<<max(n,0)<<" "<<maxx;
    return 0;
}
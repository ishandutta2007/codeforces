#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if(a>b) a=b;
typedef long long ll;
using namespace std;
int a[1000001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    cout<<n+1<<endl;
    for (int i=n;i>=1;i--){
        int x=((i-1)-a[i]%n+n)%n;
        cout<<1<<" "<<i<<" "<<x<<endl;
        for (int j=1;j<=i;j++) a[j]+=x;
    }
    cout<<2<<" "<<n<<" "<<n<<endl;
    return 0;
}
//2 6 -2 -6  2
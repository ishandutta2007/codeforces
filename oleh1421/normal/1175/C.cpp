#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;cin>>t;
    while (t--){
        int n,k;cin>>n>>k;
        vector<ll>a(n,0);
        ll minx=1000000000001ll;
        for (int i=0;i<n;i++) cin>>a[i];
        ll x=0ll;
        for (int i=0;i+k<n;i++){
            ll cur=(a[i]+a[i+k])/2ll;

            if (max(abs(a[i]-cur),abs(a[i+k]-cur))<minx){
                minx=max(abs(a[i]-cur),abs(a[i+k]-cur));
                x=cur;
            }
        }
        cout<<x<<endl;

    }
	return 0;
}
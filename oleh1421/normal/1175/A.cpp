#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;cin>>t;
    while (t--){
        ll n,k;cin>>n>>k;
        ll cnt=0;
        while (n>n%k){
            cnt+=n%k+1ll;
            n/=k;
        }
        cout<<cnt+n%k<<endl;
    }
	return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
int s[500001];
int b[500001];
int pref[500001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+n+1);
    for (int i=1;i<n;i++){
        b[i]=s[i+1]-s[i];
    }
    sort(b+1,b+n);
    for (int i=1;i<n;i++) pref[i]=pref[i-1]+b[i];
    int tt;cin>>tt;
    while (tt--){
        int l,r;cin>>l>>r;
        int x=upper_bound(b+1,b+n,r-l)-b;
        cout<<pref[x-1]+(r-l+1)*(n-x+1)<<" ";
    }
    return 0;
}
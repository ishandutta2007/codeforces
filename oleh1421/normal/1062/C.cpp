#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
ll s[100001];
ll pow2[100001];
ll mod=1000000007ll;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;cin>>n>>q;
    string c;cin>>c;
    s[0]=0ll;
    for (int i=1;i<=n;i++){
        s[i]=(c[i-1]-'0')+s[i-1];
    }
    pow2[0]=1ll;
    for (int i=1;i<=n;i++) pow2[i]=(pow2[i-1]*2ll)%mod;
    for (int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        int sum=s[r]-s[l-1];
        cout<<((pow2[sum]-1ll)*pow2[r-l+1ll-sum])%mod<<'\n';
    }
    return 0;
}
/*
35 1
1 2 3 4 5 6 7  8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
*/
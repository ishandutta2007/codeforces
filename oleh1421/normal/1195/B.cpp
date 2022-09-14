//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define checkmin(a,b) if (a>b) a=b;
#define checkmax(a,b) if (a<b) a=b;
typedef long long ll;
using namespace std;
int a[1001];
int cnt[1001];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=0;i<=1000000ll;i++){
        if (i*(i+3ll)==n+n+k+k){
            cout<<n-i;
            return 0;
        }
    }
    return 0;
}
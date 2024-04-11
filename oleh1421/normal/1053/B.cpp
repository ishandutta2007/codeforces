#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
int a[300001];
int s[300001];
int cnt[2];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) a[i]=__builtin_popcountll(a[i]);

    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for (int i=0;i<=n;i++) cnt[s[i]%2]++;
    int res=(cnt[0]*(cnt[0]-1ll))/2ll+(cnt[1]*(cnt[1]-1ll))/2ll;
    for (int i=1;i<=n;i++){
        int maxx=0;
        int sum=0;
        for (int j=i;j<=n && j<=i+100;j++){
            sum+=a[j];
            maxx=max(maxx,a[j]);
            if (sum%2==0 && maxx+maxx>sum) {
                res--;
            }
        }
    }
    cout<<res;
    return 0;
}
/*
7
0110010
1 2
1 3
1 4
2 5
2 6
3 7
*/
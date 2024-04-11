#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
int cnt[1000001];
int32_t main() {
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);*/
    int n;cin>>n;
    double s;cin>>s;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }
    int l=0;
    for (int i=1;i<=n;i++) l+=(cnt[i]==1);
    cout<<setprecision(10)<<fixed<<(s+s)/l*1.0;
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
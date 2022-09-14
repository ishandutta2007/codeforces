//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<char>v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    vector<int>a(n),b(n);
    for (int i=0;i<n;i++) cin>>a[i]>>b[i];
    int res=0;
    for (int i=0;i<=100000;i++){
        for (int j=0;j<n;j++){
            if (i>=b[j] && (i-b[j])%a[j]==0) v[j]=char(int('0')+((v[j]-'0'+1))%2);
        }
        int cur=0;
        for (int i:v) cur+=i-'0';
        res=max(res,cur);
    }
    cout<<res;
    return 0;
}
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
void solve(){
    int n;cin>>n;
    string a,b;cin>>a>>b;
    vector<int>v;
    int l=0;
    int r=n-1;
    for (int i=1;i<=n;i++){
        if (i%2){
            v.push_back(l++);
        } else {
            v.push_back(r--);
        }
    }
    int xr=1;
    vector<int>ans;

    for (int i=0;i<n;i++){
        int cur=(((a[v[i]]!=b[n-i-1]))^xr);
        if (cur) ans.push_back(1);
        ans.push_back(n-i);
        xr^=1;
    }

    cout<<ans.size()<<" ";
    for (int i:ans) {
        cout<<i<<" ";
//        for (int j=0;j<i;j++){
//            if (a[j]=='1') a[j]='0';
//            else a[j]='1';
//        }
//        reverse(a.begin(),a.begin()+i);
    }
    cout<<endl;
//    cout<<a<<" "<<b<<endl;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
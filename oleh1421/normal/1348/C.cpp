#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
string a[N];
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    sort(s.begin(),s.end());
    string res="";

    if (s[0]==s.back()){
        for (int i=1;i<=(n+k-1)/k;i++) res+=s[0];
        cout<<res<<endl;
        return;
    }
    if (s[k-1]!=s[0]){
        cout<<s[k-1]<<endl;
    } else {
        res+=s[0];
        if (s[k]==s.back()){
            for (int i=1;i<=(n-1)/k;i++) res+=s[k];
        } else {
            for (int i=k;i<n;i++) res+=s[i];
        }
        cout<<res<<endl;
    }


}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
2 3
1 100
*/
#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'

using namespace std;
const int N=200010;
const int A=10000001;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    set<char>st;
    for (auto i:s) st.insert(i);
    s="."+s;
    int cnt=0;
    for (int i=1;i<s.size();i++){
        if (s[i]!=s[i-1]) cnt++;
    }
    if (cnt==st.size()){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5 5 5
6 6 6 6 6
**/
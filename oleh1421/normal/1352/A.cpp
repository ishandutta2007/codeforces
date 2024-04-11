#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000007ll;
const int N=510;
void solve(){
    string s;cin>>s;
    vector<string>ans;
    for (int i=0;i<s.size();i++){
        if (s[i]!='0'){
            string res="";
            res+=s[i];
            for (int j=i+1;j<s.size();j++) res+='0';
            ans.push_back(res);
        }
    }
    cout<<ans.size()<<endl;
    for (auto i:ans) cout<<i<<" ";
    cout<<endl;
}
int main()
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
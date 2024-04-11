#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;

const int N=300010;
const ll mod=1000000007;
map<string,ll>dp;
map<string,string>L,R;
string t="haha";
void solve(){
    dp.clear();
    L.clear();
    R.clear();
    int n;cin>>n;
    ll res=0ll;
    for (int it=1;it<=n;it++){
        string c;cin>>c;
        string eq;cin>>eq;
        ll DP=0ll;
        string Lc="",Rc="";
        if (eq.size()==1){
            string a,b;cin>>a>>eq>>b;
            DP=dp[a]+dp[b];
            Lc=L[a];
            for (int i=0;i<min((int)L[b].size(),3-(int)L[a].size());i++) Lc+=L[b][i];
            Rc=R[b];
            reverse(Rc.begin(),Rc.end());
            for (int i=0;i<min((int)R[a].size(),3-(int)R[b].size());i++) Rc+=R[a][R[a].size()-i-1];
            reverse(Rc.begin(),Rc.end());
            string s=R[a]+L[b];
            for (int i=0;i+3<s.size();i++){
                bool ok=true;
                for (int j=0;j<4;j++){
                    ok&=(t[j]==s[j+i]);
                }
                DP+=ok;
            }
            int cnt=0;
            dp[c]=DP;
            L[c]=Lc;
            R[c]=Rc;
        } else {
            string s;cin>>s;
            dp[c]=0;
            for (int i=0;i+3<s.size();i++){
                bool ok=true;
                for (int j=0;j<4;j++){
                    ok&=(t[j]==s[j+i]);
                }
                dp[c]+=ok;
            }
            L[c]="";
            for (int i=0;i<3 && i<s.size();++i) L[c]+=s[i];
            R[c]="";
            for (int i=max((int)s.size()-3,0);i<s.size();i++) R[c]+=s[i];
        }
        res=dp[c];

    }
    cout<<res<<endl;

}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
21

h := h
a := a
b := b
x = h + a
x = x + x
x = x + b
x = x + b
x = x + x
x = a + x
x = h + x
x = h + x
x = b + x
y = h + a
y = x + y
y = x + y
y = y + b
y = x + x
y = a + y
y = y + x
x = h + y
y = y + y

**/
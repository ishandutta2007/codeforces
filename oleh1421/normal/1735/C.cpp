#include <bits/stdc++.h>
#define endl '\n'
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const ll inf=1e18;
const int N=1010;
int nxt[N];
int f(int x){
    while (nxt[x]!=-1) x=nxt[x];
    return x;
}
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    for (int i=0;i<26;i++) nxt[i]=-1;
    string ans="";
    set<int>can;
    for (int i=0;i<26;i++) can.insert(i);
    for (auto c:s){
        if (nxt[c-'a']!=-1){
            ans+=char(nxt[c-'a']+'a');
            continue;
        }
        int x=*can.begin();
        can.erase(can.begin());
        if (!can.empty() && f(x)==(c-'a')){
            int y=*can.begin();
            can.erase(can.begin());
            can.insert(x);
            x=y;
        }
        nxt[c-'a']=x;
        ans+=char(nxt[c-'a']+'a');
    }
    cout<<ans<<'\n';






}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}
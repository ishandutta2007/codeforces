#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=1000000000;
const int N=300010;
ll h[N];
int last[3];
void solve(){
    last[0]=last[1]=last[2]=-1;
    string s;cin>>s;
    int res=1000000001;
    for (int i=0;i<s.size();i++){
        last[s[i]-'1']=i;
        if (last[0]==-1 || last[1]==-1 || last[2]==-1) continue;
        res=min(res,i-min({last[0],last[1],last[2]})+1);
    }
    cout<<(res==1000000001 ? 0 : res)<<endl;


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
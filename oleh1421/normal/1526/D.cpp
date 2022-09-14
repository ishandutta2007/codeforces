#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=200010;
const int W=3010;
const double inf=1e18+5;
int a[N*2];
vector<int>g[4];
int t[N];
void upd(int n,int pos,int x){
    for (;pos<=n;pos|=pos+1) t[pos]+=x;
}
int get(int pos){
    int sum=0;
    for (;pos>=0;pos&=pos+1,pos--) sum+=t[pos];
    return sum;
}
void solve(){
    string s;cin>>s;
    string T="ANTO";
    int n=s.size();
    for (int i=0;i<4;i++) g[i].clear();
    for (int i=1;i<=n;i++){
        for (int j=0;j<4;j++){
            if (T[j]==s[i-1]){
                g[j].push_back(i);
            }
        }
    }
    vector<int>v={0,1,2,3};
    string ans="";
    ll res=-1;
    do{
        ll sum=0ll;
        vector<int>u;
        for (int i=0;i<4;i++){
            for (int j:g[v[i]]){
                u.push_back(j);
            }
        }
        reverse(u.begin(),u.end());
        for (int x:u){
            sum+=get(x);
            upd(n,x,1);
        }
        for (int i=0;i<=n;i++) t[i]=0;
        if (res<sum){
            res=sum;
            ans="";
            reverse(u.begin(),u.end());
            for (int i:u) ans+=s[i-1];
        }

    }while (next_permutation(v.begin(),v.end()));

    cout<<ans<<endl;

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
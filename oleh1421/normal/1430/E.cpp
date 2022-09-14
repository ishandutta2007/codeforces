#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
vector<int>g[N];
int p[N];
int bit[N];
void upd(int n,int pos,int x){
    for (;pos<=n;pos|=pos+1) bit[pos]+=x;
}
int get(int pos){
    int sum=0;
    for (;pos>0;pos&=pos+1,pos--) sum+=bit[pos];
    return sum;
}
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    for (int i=0;i<n;i++){
        g[s[i]-'a'].push_back(i+1);
    }
    for (int i=0;i<=25;i++){
        for (int j=0;j<g[i].size();j++){
            p[g[i][j]]=n-g[i][(int)g[i].size()-j-1]+1;
        }
    }
    for (int i=0;i<=n;i++) bit[i]=0;
    ll res=0ll;
    for (int i=1;i<=n;i++){
        res+=i-1-get(p[i]);
        upd(n,p[i],1);
    }
    cout<<res<<endl;
//    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
//    cout<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
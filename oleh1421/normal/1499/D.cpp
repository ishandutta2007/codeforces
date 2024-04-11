//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=20000010;
int p[N];
int cnt[N];
vector<pair<int,int> >v;
vector<int>D;
void F(int pos,int cur){
    if (pos==v.size()){
        D.push_back(cur);
        return;
    }
    int pw=1;
    for (int i=0;i<=v[pos].second;i++){
        F(pos+1,cur*pw);
        pw*=v[pos].first;
    }
}
void solve(){
    ll c,d,x;cin>>c>>d>>x;
    int Last=x;
    v.clear();
    D.clear();
    while (x>1){
        int cur=p[x];
        int cnt=0;
        while (x%cur==0){
            x/=cur;
            cnt++;
        }
        v.push_back({cur,cnt});
    }
    F(0,1);
    ll res=0ll;
    x=Last;
    for (ll g:D){
        if ((x+d*g)%(c*g)) continue;
        ll mult=(x+d*g)/(c*g);
//        cout<<mult<<" "<<g<<endl;
        res+=(1ll<<cnt[mult]);
    }
    cout<<res<<endl;


}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    for (int i=1;i<N;i++) p[i]=i;
    for (int i=2;i<N;i++){
        if (p[i]==i){
            for (int j=i+i;j<N;j+=i) p[j]=i;
        }
        if ((i/p[i])%p[i]==0) cnt[i]=cnt[i/p[i]];
        else cnt[i]=cnt[i/p[i]]+1;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=(1<<20);
const int T=(1<<22);
const int inf=100000000;
const ll mod=1000000007;
int TOT=1;
int a[N];
int n,k;
vector<int>order;
void rec(int l,int r,int bit){
    if (l==r) return;
    int m=(l+r)/2;
    rec(l,m,bit+1);
    order.push_back(bit);
    rec(m+1,r,bit+1);
}
struct node{
    int go[2];
    int best,mn,mx;
    node(){
        go[0]=go[1]=0;
        best=inf;
        mn=inf;
        mx=-inf;
    }
};
node t[T];
void add(int x){
    int v=1;
    for (int i=k-1;i>=0;i--){
//        if (i==k-2) cout<<"mn "<<x<<" "<<v<<endl;
        t[v].mn=min(t[v].mn,x);
        t[v].mx=max(t[v].mx,x);
        int cur=(x>>i)%2;
        if (!t[v].go[cur]) t[v].go[cur]=++TOT;
        v=t[v].go[cur];
        x^=(cur<<i);
    }
    t[v].mn=min(t[v].mn,x);
    t[v].mx=max(t[v].mx,x);
}
void build(int v,int bt){
    if (!v || bt==-1) return;
    build(t[v].go[0],bt-1);
    build(t[v].go[1],bt-1);
    t[v].best=min({t[t[v].go[0]].best,t[t[v].go[1]].best,t[t[v].go[1]].mn+(1<<bt)-t[t[v].go[0]].mx});
}
void upd(int v,int bt,int need){
    if (bt==need){
        swap(t[v].go[0],t[v].go[1]);
//        cout<<t[t[v].go[0]].mx<<" "<<t[t[v].go[1]].mx<<endl;
    } else {
        upd(t[v].go[0],bt-1,need);
        upd(t[v].go[1],bt-1,need);
    }
    if (bt==-1) exit(1);
    t[v].best=min({t[t[v].go[0]].best,t[t[v].go[1]].best,t[t[v].go[1]].mn+(1<<bt)-t[t[v].go[0]].mx});
    t[v].mn=inf;
    if (abs(t[t[v].go[0]].mn)!=inf) t[v].mn=min(t[v].mn,t[t[v].go[0]].mn);
    if (abs(t[t[v].go[1]].mn)!=inf) t[v].mn=min(t[v].mn,t[t[v].go[1]].mn+(1<<bt));
    t[v].mx=-inf;
    if (abs(t[t[v].go[0]].mx)!=inf) t[v].mx=max(t[v].mx,t[t[v].go[0]].mx);
    if (abs(t[t[v].go[1]].mx)!=inf) t[v].mx=max(t[v].mx,t[t[v].go[1]].mx+(1<<bt));
}
int ans[N];
void solve(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    rec(0,(1<<k)-1,0);
    for (int i=1;i<=n;i++){
        add(a[i]);
    }
    build(1,k-1);
    ans[0]=t[1].best;
    int x=0;
//    cout<<"M "<<t[2].mn<<endl;
    for (int i:order){
        x^=(1<<i);
        upd(1,k-1,i);
        ans[x]=t[1].best;
//        cout<<x<<" "<<t[1].best<<endl;
    }
    for (int i=0;i<(1<<k);i++) cout<<ans[i]<<" ";
    cout<<endl;

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}
//1 3 3 4
//0 1 2 3
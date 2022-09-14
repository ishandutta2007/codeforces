//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=2000010;
int a[N],b[N];
struct node{
    int sum;
    int mx;
    node(){
        sum=mx=0;
    }
};
node Merge(node A,node B){
    node C;
    C.sum=A.sum+B.sum;
    C.mx=max({A.mx,A.sum+B.mx,0});
    return C;
}
node t[N*4];
void upd(int v,int l,int r,int pos,int x){
    if (l==r){
        t[v].sum=x;
        t[v].mx=max(x,0);
        return;
    }
    int m=(l+r)/2;
    if (pos<=m) upd(v+v,l,m,pos,x);
    else upd(v+v+1,m+1,r,pos,x);
    t[v]=Merge(t[v+v],t[v+v+1]);
}

int T[N];
void add(int n,int pos,int x){
    for (;pos<=n;pos|=pos+1) T[pos]+=x;
}
int S(int pos){
    int sum=0;
    for(;pos>=0;pos&=pos+1,pos--) sum+=T[pos];
    return sum;
}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    sort(b+1,b+m+1);
    vector<pair<int,int> >v;
    for (int i=1;i<=n;i++){
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    for (int i=1;i<=n;i++) upd(1,1,n,i,-1);
    ll res=0ll;
    int ind1=0,ind0=0;
    for (int i=1;i<=m;i++){
        while (ind0<v.size() && v[ind0].first<=b[i]){
            upd(1,1,n,v[ind0].second,0);
            ind0++;
        }
        while (ind1<v.size() && v[ind1].first<b[i]){
            upd(1,1,n,v[ind1].second,1);
            ind1++;
        }
        res+=ind1-t[1].mx;
    }
    set<int>st;
    for (int i=1;i<=n;i++){
        st.insert(a[i]);
    }
    map<int,int>mp;
    int cnt=0;
    for (int x:st){
        mp[x]=++cnt;
    }
    for (int i=1;i<=n;i++) a[i]=mp[a[i]];
    for (int i=1;i<=n;i++){
        res+=i-S(a[i])-1;
        add(cnt,a[i],1);
    }
    for (int i=0;i<=cnt;i++) T[i]=0;
    for (int i=0;i<=n*4;i++) t[i]=node();
    cout<<res<<endl;
}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
3
3 1
1 1 1
5
3 1
1 1 1
5
3 1
1 1 1
5
**/
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const ll mod=998244353ll;
const int N=200010;
int x[N];
int p[N];
map<int,int>mp;
struct node{
    bool empt;
    int mn,mx,res;
};
node t[N*4];
void build(int v,int l,int r){
    if (l>r) return;
    t[v].empt=true;
    t[v].mn=t[v].mx=t[v].res=-1;
    if (l==r) return;
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
}
node Merge(node A,node B){
    if (A.empt) return B;
    if (B.empt) return A;
    node C;
    C.empt=false;
    C.mn=A.mn;
    C.mx=B.mx;
    C.res=max({A.res,B.res,B.mn-A.mx});
    return C;
}
void upd(int v,int l,int r,int pos,int x){
    if (l==r){
        if (t[v].empt){
            t[v].empt=false;
            t[v].mn=t[v].mx=x;
            t[v].res=0;
        } else {
            t[v].empt=true;
            t[v].mn=t[v].mx=t[v].res=-1;
        }
        return;
    }
    int m=(l+r)/2;
    if (pos<=m) upd(v+v,l,m,pos,x);
    else upd(v+v+1,m+1,r,pos,x);
    t[v]=Merge(t[v+v],t[v+v+1]);
}
int ans(){
    if (t[1].empt) return 0;
    return t[1].mx-t[1].mn-t[1].res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=m;i++){
        int t;cin>>t>>x[i];
    }
    set<int>st;
    for (int i=1;i<=n;i++){
        st.insert(p[i]);
    }
    for (int i=1;i<=m;i++){
        st.insert(x[i]);
    }
    int k=0;
    for (int i:st){
        mp[i]=++k;
    }
    build(1,1,k);
    for (int i=1;i<=n;i++){
//        cout<<mp[p[i]]<<endl;
        upd(1,1,k,mp[p[i]],p[i]);
//    cout<<t[1].mn<<" "<<t[1].mx<<endl;

    }
    cout<<ans()<<endl;
    for (int i=1;i<=m;i++){
        upd(1,1,k,mp[x[i]],x[i]);
        cout<<ans()<<endl;
    }

    return 0;
}
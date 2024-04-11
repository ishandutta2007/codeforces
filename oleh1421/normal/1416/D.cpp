#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const int inf=1000000001;
int arr[N];
int a[N];
int b[N];
int type[N];
int X[N];
int L[N];
int R[N];
vector<int>Q[N];
int p[N];
int dsu[N];
vector<int>cmp[N];
int get(int x){
    if (dsu[x]==x) return x;
    return dsu[x]=get(dsu[x]);
}
void unite(int x,int y){
    x=get(x);
    y=get(y);
    if (x==y) return;
    if (cmp[x].size()>cmp[y].size()) swap(x,y);
    dsu[x]=y;
    int sz=cmp[y].size();
    for (int v:cmp[x]){
        p[v]+=sz;
        cmp[y].push_back(v);
    }
    cmp[x].clear();
}
bool del[N];
int mn[N];
int mx[N];
int dsu1[N];
int get1(int x){
    if (dsu1[x]==x) return x;
    return dsu1[x]=get1(dsu1[x]);
}
void unite1(int x,int y){
    x=get1(x);
    y=get1(y);
    if (x!=y){
        mn[y]=min(mn[y],mn[x]);
        mx[y]=max(mx[y],mx[x]);
        dsu1[x]=y;
    }
}
pair<int,int>t[N*4];
void upd(int v,int l,int r,int pos,int x){
    if (l==r){
        t[v]={x,pos};
        return;
    }
    int m=(l+r)/2;
    if (pos<=m) upd(v+v,l,m,pos,x);
    else upd(v+v+1,m+1,r,pos,x);
    t[v]=max(t[v+v],t[v+v+1]);
}
pair<int,int>get_mx(int v,int l,int r,int L,int R){
    if (l>R || r<L) return {0,0};
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return max(get_mx(v+v,l,m,L,R),get_mx(v+v+1,m+1,r,L,R));

}
void solve(){
    int n,m,q;cin>>n>>m>>q;
    for (int i=1;i<=n;i++) cin>>arr[i];
    for (int i=1;i<=m;i++) cin>>a[i]>>b[i];
    for (int i=1;i<=q;i++) {
        cin>>type[i]>>X[i];
        if (type[i]==2) del[X[i]]=true;
    }
    for (int i=1;i<=n;i++) p[i]=1,dsu[i]=i,cmp[i]={i};
    for (int i=1;i<=m;i++){
        if (!del[i]){
            unite(a[i],b[i]);
        }
    }
    for (int i=q;i>=1;i--){
        if (type[i]==2){
            unite(a[X[i]],b[X[i]]);
        }
    }

    for (int i=2;i<=n;i++){
        unite(1,i);

    }
    for (int i=1;i<=n;i++){
        dsu1[i]=i;
        mn[i]=p[i];
        mx[i]=p[i];
    }
    for (int i=1;i<=m;i++){
        if (!del[i]){
            unite1(a[i],b[i]);
        }
    }
    for (int i=q;i>=1;i--){
        if (type[i]==2){
            unite1(a[X[i]],b[X[i]]);
        } else {
            L[i]=mn[get1(X[i])];
            R[i]=mx[get1(X[i])];
//            cout<<"Q "<<i<<" "<<L[i]<<" "<<R[i]<<endl;
        }
    }
    for (int i=1;i<=n;i++){
        upd(1,1,n,p[i],arr[i]);
    }
    for (int i=1;i<=q;i++){
        if (type[i]==1){
            auto cur=get_mx(1,1,n,L[i],R[i]);
            cout<<cur.first<<endl;
            upd(1,1,n,cur.second,0);
        }
    }
//    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
//    cout<<endl;



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
8 7
1 7 5 6 8 2 6 5

*/
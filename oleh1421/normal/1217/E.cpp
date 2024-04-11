#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int unsigned int
typedef long long ll;
using namespace std;
int inf=2000000007;
struct node{
      int d[10];
      int val;
};
node t[600001];
node marge(node t1,node t2){
     node res;
     res.val=min(t1.val,t2.val);
     for (int i=0;i<=9;i++){
        res.val=min(res.val,t1.d[i]+t2.d[i]);
        //cout<<i<<" "<<t1.d[i]<<" "<<t2.d[i]<<endl;
        res.d[i]=min(t1.d[i],t2.d[i]);
     }
     return res;
}
int a[200002];
void build(int v,int l,int r){
     if (l==r){
            if (v>600000){
                cout<<v<<endl;
                cout<<"OK\n";
                exit(0);
            }
        t[v].val=inf;
        for (int i=0;i<=9;i++) t[v].d[i]=inf;
        int x=a[l];
        int cnt=0;
        while (x){
            if (x%10) t[v].d[cnt]=a[l];
            x/=10;
            cnt++;
        }
        return;
     }
     int m=(l+r)/2;
     build(v+v,l,m);
     build(v+v+1,m+1,r);
     t[v]=marge(t[v+v],t[v+v+1]);
}
void upd(int v,int l,int r,int pos,int x){
     if (l>pos || r<pos) return;
     if (l==r){
        t[v].val=inf;
        for (int i=0;i<=9;i++) t[v].d[i]=inf;
        a[l]=x;
        int cnt=0;
        while (x){
            if (x%10) t[v].d[cnt]=a[l];
            x/=10;
            cnt++;
        }
        return;
     }
     int m=(l+r)/2;
     upd(v+v,l,m,pos,x);
     upd(v+v+1,m+1,r,pos,x);
     t[v]=marge(t[v+v],t[v+v+1]);
}
node emp;
node get(int v,int l,int r,int L,int R){
     if (l>R || r<L) return emp;
     if (l>=L && r<=R) return t[v];
     int m=(l+r)/2;
     return marge(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    emp.val=inf;
    for (int i=0;i<=9;i++) emp.d[i]=inf;
    while (m--){
        int type;cin>>type;
        if (type==1){
            int i,x;cin>>i>>x;
            upd(1,1,n,i,x);
        } else {
            int l,r;cin>>l>>r;
            int res=get(1,1,n,l,r).val;
            if (res>=inf) cout<<"-1\n";
            else cout<<res<<endl;
        }
    }
    return 0;
}
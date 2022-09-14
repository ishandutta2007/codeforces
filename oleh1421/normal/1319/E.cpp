#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=200010;
int a[N];
int ac[N];
int b[N];
int bc[N];
int x[N];
int y[N];
int z[N];
int t[N*4];
int w[N*4];
void push(int v){
    t[v+v]+=w[v];
    t[v+v+1]+=w[v];
    w[v+v]+=w[v];
    w[v+v+1]+=w[v];
    w[v]=0;
}
void upd(int v,int l,int r,int L,int R,int x){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        t[v]+=x;
        w[v]+=x;
        return;
    }
    push(v);
    int m=(l+r)/2;
    upd(v+v,l,m,L,R,x);
    upd(v+v+1,m+1,r,L,R,x);
    t[v]=max(t[v+v],t[v+v+1]);
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return -2000000001;
    if (l>=L && r<=R) return t[v];
    push(v);
    int m=(l+r)/2;
    return max(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>a[i]>>ac[i];
    for (int i=1;i<=m;i++) cin>>b[i]>>bc[i];
    for (int i=1;i<=k;i++) cin>>x[i]>>y[i]>>z[i],x[i]++,y[i]++;
//    for (int i=1;i<=n;i++) a[i]=rand()%200,ac[i]=rand()%200;
//    for (int i=1;i<=m;i++) b[i]=rand()%200,bc[i]=rand()%200;
//    for (int i=1;i<=k;i++) x[i]=rand()%200,y[i]=rand()%200,z[i]=rand()%200,x[i]++,y[i]++;
//    for (int i=1;i<=n;i++) cout<<a[i]<<" "<<ac[i]<<endl;
//    for (int i=1;i<=m;i++) cout<<b[i]<<" "<<bc[i]<<endl;
//    for (int i=1;i<=k;i++) cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<endl;
    vector<pair<int,int> >v;
    for (int i=n;i>=1;i--){
        v.push_back({a[i],ac[i]});
    }
    vector<pair<int,int> >u;
    for (int i=m;i>=1;i--){
        u.push_back({b[i],bc[i]});
    }
    sort(v.begin(),v.end());
    for (int i=n-2;i>=0;i--) v[i].second=min(v[i].second,v[i+1].second);
    sort(u.begin(),u.end());
    vector<pair<int,pair<int,int> > >q;
    for (int i=1;i<=k;i++) q.push_back({x[i],{y[i],z[i]}});
    sort(q.begin(),q.end());
    int res=0;
    int mn1=1000000001;
    int mn2=1000000001;
    for (int i=1;i<=n;i++) mn1=min(mn1,ac[i]);
    for (int i=1;i<=m;i++) mn2=min(mn2,bc[i]);
    res-=mn1;
    res-=mn2;
    for (int i=0;i<u.size();i++){
        upd(1,0,(int)u.size()-1,i,i,-u[i].second);
    }
    for (int i=0;i<k;i++){
        int x=q[i].first;
        int y=q[i].second.first;
        int z=q[i].second.second;
        pair<int,int>fnd;
        fnd={x,-1};
        int ind1=lower_bound(v.begin(),v.end(),fnd)-v.begin();
        bool ok=false;
        if (ind1==v.size()) ok=true,ind1--;
        fnd={y,-1};
        int ind2=lower_bound(u.begin(),u.end(),fnd)-u.begin();
        if (ind2<u.size() && !ok) upd(1,0,(int)u.size()-1,ind2,(int)u.size()-1,z);
        res=max(res,t[1]-v[ind1].second);
//        if (ind1==10) cout<<"sol:"<<t[1]-v[ind1].second<<endl;
    }
    cout<<res<<endl;
//    int maxx=-2000000001;
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=m;j++){
//            int sum=0;
//            for (int t=1;t<=k;t++){
//                if (x[t]<=a[i] && y[t]<=b[j]) sum+=z[t];
//            }
//            maxx=max(maxx,sum-ac[i]-bc[j]);
//            if (sum-ac[i]-bc[j]==3741) cout<<"brute:"<<i<<" "<<j<<endl;
//        }
//    }
//    cout<<maxx;
    return 0;
}
/*
    int mn1=1000000001;
    int mn2=1000000001;
    for (int i=1;i<=n;i++) mn1=min(mn1,ac[i]);
    for (int i=1;i<=m;i++) mn2=min(mn2,bc[i]);
    res-=mn1;
    res-=mn2;
    45 4 45

*/
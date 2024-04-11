//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=1000010;
int s[N],a[N];
int t[N*4],w[N*4];
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
    if (l>R || r<L) return 0;
    if (l>=L && r<=R) return t[v];
    push(v);
    int m=(l+r)/2;
    return max(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    int n,d;cin>>n>>d;
    vector<pair<int,pair<int,int> > >v;
    for (int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if (x<d) continue;
        v.push_back({x+y,{x,y}});
    }
    sort(v.begin(),v.end());

    n=v.size();
    for (int i=0;i<n;i++){
        s[i+1]=v[i].second.first;
        a[i+1]=v[i].second.second;
    }
    vector<int>V;
    for (int i=1;i<=n;i++){
        V.push_back(a[i]);
        V.push_back(s[i]);
    }
    sort(V.begin(),V.end());
    for (int i=1;i<=n;i++) {
        a[i]=lower_bound(V.begin(),V.end(),a[i])-V.begin()+1;
        s[i]=lower_bound(V.begin(),V.end(),s[i])-V.begin()+1;
    }
//    for (int i=1;i<=n;i++) cout<<a[i]<<" "<<s[i]<<endl;
    int cnt=V.size();
    for (int i=1;i<=n;i++){
        if (a[i]<s[i]){
            upd(1,0,cnt,a[i]+1,s[i],1);
        }
        int cur=get(1,0,cnt,0,min(s[i],a[i]))+1;
        int last=get(1,0,cnt,a[i],a[i]);
        upd(1,0,cnt,a[i],a[i],cur-last);
    }
    cout<<t[1]<<endl;

}
int32_t  main()
{
//    cout<<mod<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
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
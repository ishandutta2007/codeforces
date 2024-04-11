#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=1000100;
const ll mod=998244353;
int p[N];
int l[N],r[N];
int val[N];
vector<int>Q[N];
int pos[N];
ll ans[N];
int go[N];
int go1[N];
vector<int>d[N];
//int A[1010][1010];
struct SegTree{
    ll t[N*4];
    ll w[N*4];
    ll sz[N*4];
    void push(int v){
        t[v+v]+=w[v]*sz[v+v];
        t[v+v+1]+=w[v]*sz[v+v+1];
        w[v+v]+=w[v];
        w[v+v+1]+=w[v];
        w[v]=0;
    }
    void build(int v,int l,int r){
        t[v]=w[v]=0;
        sz[v]=r-l+1;
        if (l==r) return;
        int m=(l+r)/2;
        build(v+v,l,m);
        build(v+v+1,m+1,r);
    }
    void upd(int v,int l,int r,int L,int R,int x){
        if (l>R || r<L) return;
        if (l>=L && r<=R){
            t[v]+=x*sz[v];
            w[v]+=x;
            return;
        }
        push(v);
        int m=(l+r)/2;
        upd(v+v,l,m,L,R,x);
        upd(v+v+1,m+1,r,L,R,x);
        t[v]=t[v+v]+t[v+v+1];
    }
    ll get(int v,int l,int r,int L,int R){
        if (l>R || r<L) return 0;
        if (l>=L && r<=R) return t[v];
        push(v);
        int m=(l+r)/2;
        return get(v+v,l,m,L,R)+get(v+v+1,m+1,r,L,R);
    }
};
vector<pair<int,int> >A[N];
vector<pair<pair<int,int>,int> >B[N];
void add(int x1,int y1,int x2,int y2){
    if (x1>x2 || y1>y2) return;
//    cout<<"add "<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
//    for (int i=x1;i<=x2;i++){
//        for (int j=y1;j<=y2;j++){
//            A[i][j]++;
//        }
//    }
    A[x2].push_back({y1,y2});
    B[x1].push_back({{y1,y2},x2});
}
SegTree T1,T2,T3;
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>p[i],pos[p[i]]=i;
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j+=i) d[j].push_back(i);
    }
    for (int i=n;i>=1;i--){
        go[i]=n+1;
        for (int j=i+1;j<=n;j=go[j]){
            if (p[j]>p[i]){
                go[i]=j;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++){
        go1[i]=0;
        for (int j=i-1;j>=1;j=go1[j]){
            if (p[j]>p[i]){
                go1[i]=j;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++){
        vector<pair<int,int> >v;
        for (int j:d[p[i]]){
            if (j==p[i]/j) continue;
            int l=min({i,pos[j],pos[p[i]/j]});
            int r=max({i,pos[j],pos[p[i]/j]});
            if (l>go1[i] && r<go[i]){
                v.push_back({l,r});
            }
        }

        sort(v.begin(),v.end());
        for (int i=(int)v.size()-2;i>=0;i--){
            v[i].second=min(v[i].second,v[i+1].second);
        }
        int last=go1[i];
        for (int j=0;j<v.size();j++){
            add(last+1,v[j].second,v[j].first,go[i]-1);
            last=v[j].first;
        }

    }
    for (int i=1;i<=q;i++) {
        cin>>l[i]>>r[i];
        Q[l[i]].push_back(i);
    }
    T1.build(1,1,n);
    T2.build(1,1,n);
    T3.build(1,1,n);
    for (int i=n;i>=1;i--){
        for (auto cur:A[i]){
            T1.upd(1,1,n,cur.first,cur.second,i);
            T2.upd(1,1,n,cur.first,cur.second,1);
        }
        for (auto cur:B[i]){
            T1.upd(1,1,n,cur.first.first,cur.first.second,-cur.second);
            T2.upd(1,1,n,cur.first.first,cur.first.second,-1);
            T3.upd(1,1,n,cur.first.first,cur.first.second,cur.second-i+1);
//            cout<<"A "<<cur.first.first<<" "<<cur.first.second<<" "<<cur.second-i+1<<endl;
        }
        for (int j:Q[i]){
            ll a1=T1.get(1,1,n,1,r[j]);
            ll a2=T2.get(1,1,n,1,r[j]);
            ll a3=T3.get(1,1,n,1,r[j]);
//            cout<<j<<" "<<a1<<" "<<a2<<" "<<a3<<endl;
            ans[j]=a3+a1-a2*(i-1);
        }
    }
//    for (int i=1;i<=n;i++) val[i]=n+1;
//    vector<int>st;
//    for (int i=n;i>=1;i--){
//        for (int j=1;j*p[i]<=n;j++){
//            if (j==p[i]) continue;
//            if (pos[j*p[i]]>=i && pos[j]>=i) {
//                int cur=max(pos[j],pos[j*p[i]]);
//                if (cur>=go[pos[j*p[i]]]) continue;
//                if (val[j*p[i]]<cur) continue;
//                if (val[j*p[i]]==n+2) continue;
//                val[j*p[i]]=cur;
//            }
//        }
//        while (!st.empty() && p[st.back()]<p[i]){
//            val[p[st.back()]]=n+2;
//            st.pop_back();
//        }
//        st.push_back(i);
//        for (int t=1;t<=n;t++) cout<<val[t]<<" ";
//        cout<<endl;
//        for (int j:Q[i]){
//            int res=0;
//            for (int t=1;t<=n;t++) {
//                res+=max(r[j]-val[t]+1,0);
//            }
//            ans[j]+=res;
//        }
//    }
    for (int i=1;i<=q;i++) cout<<ans[i]<<endl;



}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

/**
8 1
1 3 5 2 4 7 6 8
1 8


1
5 2
-1 1 2 0 0


4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/
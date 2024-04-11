#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
#define __int128_t ll
const int N=600010;
int a[N],b[N],c[N],ind[N];
vector<int>g[N];
int dsu[N];
int sz[N];
int E[N];
int mn[N];
int last[N];
int get(int x){
    if (dsu[x]==x) return x;
    return dsu[x]=get(dsu[x]);
}
ll calc(int n,int cur,int blocked){
    ll sum=0ll;
    for (int i=1;i<=n;i++) last[i]=dsu[i];
    for (int i=1;i<=cur;i++){
        if (ind[i]==blocked) continue;
        int x=get(a[i]);
        int y=get(b[i]);
        if (x!=y){
            sum+=c[i];
            dsu[x]=y;
        }
    }
    for (int i=1;i<=n;i++) dsu[i]=last[i];
    return sum;

}
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        dsu[i]=0;
        mn[i]=(1<<30);
    }
    int Xr=0;
    for (int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>c[i];
        Xr^=c[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    set<int>st;
    for (int i=1;i<=n;i++) st.insert(i);
    int cur=m;
    for (int i=1;i<=n;i++){
        if (dsu[i]) continue;
        queue<int>q;
        q.push(i);
        st.erase(i);
        dsu[i]=i;
        while (!q.empty()){
            int v=q.front();
            q.pop();
            vector<int>del;
            for (int to:g[v]){
                if (st.find(to)!=st.end()){
                    del.push_back(to);
                    st.erase(to);
                }
            }
            for (int to:st){
                dsu[to]=i;
                cur++;
                a[cur]=v;
                b[cur]=to;
                c[cur]=0;
                q.push(to);
            }
            st.clear();
            for (int i:del) st.insert(i);
        }
    }
    for (int i=1;i<=n;i++) sz[dsu[i]]++;
    for (int i=1;i<=m;i++){
        if (dsu[a[i]]==dsu[b[i]]) E[dsu[a[i]]]++;
    }
    bool ok=false;
    for (int i=1;i<=n;i++){
        if (sz[i]>1){
            if (E[i]*1ll==(sz[i]*1ll)*(sz[i]-1ll)/2ll-sz[i]+1ll) continue;
            ok=true;
        }
    }
    vector<pair<pair<int,int> ,pair<int,int> > >v;
    for (int i=1;i<=cur;i++){
        v.push_back({{c[i],i},{a[i],b[i]}});
    }
    sort(v.begin(),v.end());
    for (int i=0;i<cur;i++){
        c[i+1]=v[i].first.first;
        ind[i+1]=v[i].first.second;
        a[i+1]=v[i].second.first;
        b[i+1]=v[i].second.second;
    }
    if (ok){
        cout<<calc(n,cur,-1)<<endl;
        return;
    }
//    for (int i=1;i<=n;i++) cout<<dsu[i]<<" ";
//    cout<<endl;
    ll res=Xr+calc(n,cur,-1);
//    cout<<res<<endl;

    for (int i=1;i<=n;i++) dsu[i]=i;
    for (int i=m+1;i<=cur;i++){

        res=min(res,calc(n,cur,i));
    }
    cout<<res<<endl;

}

int32_t main()
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
///C=MEX(A)^B + MEX(B)^A
///MEX(C)=MEX(A)^MEX(B)
///A - DONE
//a b c
//a b c d

//0 1 2 3
//0 1 2 3
//0 1 2 3
//
//1+1+1+1+

/**
1 3
0.0 0.1 0.5 0.2
**/
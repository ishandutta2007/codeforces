#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=100010;
const ll mod=1000000007;
int l[N];
int r[N];
vector<int>Q[N];
int n,m;
int ans[N];
set<pair<int,int> >st[N*4];
void Insert(int v,int a,int b){
    auto it=st[v].upper_bound({a,1000000001});
    if (it!=st[v].begin()){
        it--;
        if ((*it).second<=b) return;
    }
    while (true){
        it=st[v].lower_bound({a,-1});
        if (it!=st[v].end() && (*it).second>=b) st[v].erase(it);
        else break;
    }
    st[v].insert({a,b});
}
void upd(int v,int l,int r,int x,int y,int z){
    ///Insert {y,z} in st[v]
    Insert(v,y,z);
    if (l==r) return;
    int m=(l+r)/2;
    if (x<=m) upd(v+v,l,m,x,y,z);
    else upd(v+v+1,m+1,r,x,y,z);
}
int get(int v,int l,int r,int L,int R,int x){
    if (l>R || r<L) return m+1;
    if (l>=L && r<=R){
        auto it=st[v].upper_bound({x,1000000001});
        if (it==st[v].begin()) return m+1;
        it--;
        return (*it).second;
    }
    int m=(l+r)/2;
    return min(get(v+v,l,m,L,R,x),get(v+v+1,m+1,r,L,R,x));
}
void solve(){

    cin>>n>>m;
    for (int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
        Q[r[i]-l[i]+1].push_back(i);
    }
    for (int x=n;x>=1;x--){
        for (int i:Q[x]){
            upd(1,1,n,l[i],r[i],i);
        }
        set<pair<int,pair<int,int> > >st;
        st.insert({get(1,1,n,1,n,n),{1,n}});
        int res=0;
        while ((*st.begin()).first<=m){
            auto cur=(*st.begin());
            int ind=cur.first;
            int L=cur.second.first;
            int R=cur.second.second;
            st.erase(st.begin());
            res+=r[ind]-l[ind]+1;
            st.insert({get(1,1,n,L,n,l[ind]-1),{L,l[ind]-1}});
            st.insert({get(1,1,n,r[ind]+1,n,R),{r[ind]+1,R}});
        }
        ans[x]=res;
    }
    for (int i=1;i<=n;i++) cout<<ans[i]<<endl;
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
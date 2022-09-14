//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse,avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 rnd(time(NULL));
const int N=500100;
const ll mod=1000000007;
int c[N],l[N],r[N];
int add[2][N];
int a[2][N];
int b[2][N];
int L[2][N];
int R[2][N];
int n;
int m[2];
set<int>st[2];
bool used[2][N];
void dfs(int j,int pos){
    used[j][pos]=true;
    st[j].erase(pos);
    while (true){
        auto it=st[j^1].lower_bound(a[j][pos]);
        if (it==st[j^1].end() || (*it)>b[j][pos]){
            break;
        }
        int to=(*it);
//        cout<<j<<" "<<pos<<" "<<to<<" "<<L[j][pos]<<" "<<R[j][pos]<<" "<<L[j^1][to]<<" "<<R[j^1][to]<<endl;

        dfs(j^1,to);
    }
}
void solve(int Case){
    cin>>n;
    vector<int>cord;
    for (int i=1;i<=n;i++) {
        cin>>c[i]>>l[i]>>r[i];
        cord.push_back(l[i]);
        cord.push_back(r[i]);
    }
    sort(cord.begin(),cord.end());
    for (int i=1;i<=n;i++){
        l[i]=lower_bound(cord.begin(),cord.end(),l[i])-cord.begin()+1;
        r[i]=lower_bound(cord.begin(),cord.end(),r[i])-cord.begin()+1;
    }
    for (int i=0;i<=cord.size();i++){
        add[0][i]=add[1][i]=0;
    }
    for (int i=1;i<=n;i++) {
        add[c[i]][l[i]]++;
        add[c[i]][r[i]+1]--;
    }
    for (int i=1;i<=cord.size();i++){
        add[0][i]+=add[0][i-1];
        add[1][i]+=add[1][i-1];
    }

    for (int i=1;i<=cord.size();i++){
        add[0][i]+=add[0][i-1];
        add[1][i]+=add[1][i-1];
    }
    vector<pair<int,int> >v[2];
    int res=0;
    for (int i=1;i<=n;i++){
        int sum=add[c[i]^1][r[i]]-add[c[i]^1][l[i]-1];
        if (sum==0){
            res++;
//            cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
        } else {
            v[c[i]].push_back({l[i],-r[i]});
        }
    }
    for (int i=0;i<=cord.size();i++){
        add[0][i]=add[1][i]=0;
    }
//    cout<<"A "<<res<<endl;
    for (int i=0;i<2;i++){
        sort(v[i].begin(),v[i].end());
        vector<pair<int,int> >u;
        int R=0;
        for (auto cur:v[i]){
            cur.second=-cur.second;
            if (R>=cur.second) continue;
            R=cur.second;
            u.push_back(cur);
        }
        v[i]=u;

    }
    for (int j=0;j<2;j++){
        m[j]=v[j].size();
        st[j].clear();

        for (int i=0;i<m[j];i++){
            L[j][i]=v[j][i].first;
            R[j][i]=v[j][i].second;
            st[j].insert(i);
            used[j][i]=false;
        }
    }
    for (int j=0;j<2;j++){
        for (int i=0;i<m[j];i++){
            a[j][i]=lower_bound(R[j^1],R[j^1]+m[j^1],L[j][i])-R[j^1];
            b[j][i]=upper_bound(L[j^1],L[j^1]+m[j^1],R[j][i])-L[j^1]-1;
        }
    }
    for (int j=0;j<2;j++){
        for (int i=0;i<m[j];i++){
            if (!used[j][i]){
                dfs(j,i);
                res++;
            }
        }
    }
    st[0].clear();
    st[1].clear();
    cout<<res<<endl;




}
int32_t main() {
//    freopen("seabattle.in","r",stdin);
//    freopen("seabattle.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
5
0 0 5
1 2 12
0 4 7
1 9 16
0 13 19
**/
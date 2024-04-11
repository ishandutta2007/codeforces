#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(NULL));
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N=100010;
const int L=20;
const ll mod=998244353;
int a[N];


vector<int>A[N*4];
int TOT=0;
void build(int v,int l,int r){
    A[v].clear();
    for (int i=l;i<=r;i++){
        A[v].push_back(a[i]);
    }
    sort(A[v].begin(),A[v].end());
    if (l==r) return;
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
}
struct node{
    int v,l,r;
    int cnt(){
        if (l>r) return 0;
        return r-l+1;
    }
};
vector<node>roots;
void dfs(int v,int l,int r,int L,int R){
    if (l>R || r<L) return;
    if (l>=L && r<=R){
        roots.push_back({v,0,r-l});
        return;
    }
    int m=(l+r)/2;
    dfs(v+v,l,m,L,R);
    dfs(v+v+1,m+1,r,L,R);
}
vector<int>order;
int res;
void rec(vector<node>v,int bt,int pref){
    if (bt==-1){
        int cn=0;
        for (auto i:v){
            cn+=i.cnt();
        }
        if (cn>=2) res=min(res,pref);
        else if (cn==1) order.push_back(pref);
        return;
    }
    vector<int>ind;
    int cnt0=0;
    int cnt1=0;
    for (auto i:v){
        int cur=lower_bound(A[i.v].begin()+i.l,A[i.v].begin()+i.r+1,pref+(1<<bt))-A[i.v].begin();
        ind.push_back(cur);
        if (i.l<cur) cnt0+=cur-i.l;
        if (cur<=i.r) cnt1+=i.r-cur+1;
    }
    if (cnt0>=2){
        for (int i=0;i<v.size();i++){
            v[i].r=ind[i]-1;
        }
        rec(v,bt-1,pref);
        return;
    }
    if (cnt0==1){
        for (int i=0;i<v.size();i++){
            if (v[i].l<ind[i]){
                order.push_back(A[v[i].v][v[i].l]);
                break;
            }
        }
    }
    for (int i=0;i<v.size();i++){
        v[i].l=ind[i];
    }
    rec(v,bt-1,pref+(1<<bt));
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    int q;cin>>q;
    for (int i=1;i<=q;i++){
        int l,r;cin>>l>>r;
        roots.clear();
        order.clear();
        dfs(1,1,n,l,r);
        res=(1<<30)-1;
        rec(roots,29,0);
        for (int j=0;j<order.size();j++){
            for (int t=j+1;t<order.size();t++){
                res=min(res,(order[j]|order[t]));
            }
        }
        cout<<res<<endl;
    }


}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
1
5
6 1 3 2 1
1
2 3
**/
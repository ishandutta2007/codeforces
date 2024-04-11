//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const int N=200010;
const int K=155;
const ll inf=1000000000000000001;
int p[N];
vector<int>g[N];
int t[N];
void upd(int n,int pos,int x){
    for (;pos<=n;pos|=pos+1) t[pos]+=x;
}
int get(int pos){
    int sum=0;
    for (;pos>=0;pos&=pos+1,pos--){
        sum+=t[pos];
    }
    return sum;
}
void solve(){
    int n,x;cin>>n>>x;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        p[x]=i;
    }
    int root=-1;
    for (int i=1;i<=n;i++){
        if (g[i].size()==n-1) root=i;
    }
    if (root==-1 || is_sorted(p+1,p+n+1)){
        cout<<"Alice\n";
        return;
    }
    ll inv=0ll;
    for (int i=1;i<=n;i++){
        inv+=get(n-p[i]+1);
        upd(n,n-p[i]+1,1);
    }
    for (int i=0;i<=n;i++) t[i]=0;
    if (root==x){
        if (p[root]!=root){
            cout<<"Bob\n";
            return;
        }
        if (inv%2==0){
            cout<<"Bob\n";
            return;
        }
        cout<<"Alice\n";
        return;
    } else {
        if (p[x]==root){
            cout<<"Bob\n";
            return;
        }

        if (n==3 && p[root]==root){
            cout<<"Bob\n";
            return;
        }
        int cnt=0;
        for (int i=1;i<=n;i++) cnt+=(p[i]!=i);
        if (p[x]==x && cnt==2){
            cout<<"Alice\n";
            return;
        }
        if (inv%2){
            cout<<"Bob\n";
            return;
        }
        cout<<"Alice\n";

    }





}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
6 7
1 2 1
2 3 3
3 1 5
4 5 2
5 6 4
6 4 6
3 4 1
1
5 1

**/
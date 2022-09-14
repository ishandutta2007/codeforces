//#pragma GCC opitmize ("trapv")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=200010;
const int L=29;
int t[N*L+N][2];
int cnt[N*L+N];
int a[N];
int num_of_v=0;
void init(){
    for (int i=0;i<=num_of_v;i++){
        t[i][0]=t[i][1]=0;
        cnt[i]=0;
    }
    num_of_v=1;
}
void add(int x){
    int v=1;
    cnt[v]++;
    for (int i=L;i>=0;i--){
        int cur=((x>>i)&1);
        if (!t[v][cur]) t[v][cur]=++num_of_v;
        v=t[v][cur];
        cnt[v]++;
    }
}
ll get_mn(int x){
//    cout<<x<<" "<<j<<endl;
    int v=1;
    int y=0;
    for (int i=L;i>=0;i--){
        int cur=((x>>i)&1);
        if (cnt[t[v][cur]]) v=t[v][cur];
        else v=t[v][cur^1],y^=(1<<i);
    }
    return y;
}
ll solve(int l,int r,int b){
    if (l>=r || b<0) return 0;
    int m=l-1;
    while (m+1<=r && (a[m+1]&(1<<b))==0) m++;
    for (int i=m+1;i<=r;i++){
        a[i]^=(1<<b);
    }
    if (m+1>r || m<l) return solve(l,r,b-1);
    init();
    for (int i=l;i<=m;i++){
        add(a[i]);
    }
    ll minx=2000000001ll;
    for (int i=m+1;i<=r;i++){
        minx=min(minx,get_mn(a[i]));
    }
    minx^=(1ll<<b);
    return minx+solve(l,m,b-1)+solve(m+1,r,b-1);
}
int32_t main()
{
//    freopen("landscape.in","r",stdin);
//    freopen("landscape.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<solve(1,n,L);
    return 0;
}
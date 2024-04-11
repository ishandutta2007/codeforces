/**
 *    author:  gary
 *    created: 24.04.2022 20:13:29
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+20;
int n,v,dp[MAXN],a[MAXN],t[MAXN];
LL c[MAXN];
int tree[MAXN];
void chkmax(int pos,int val){
    while (pos<MAXN)
    {
        check_max(tree[pos],val);
        pos+=pos&-pos;
    }
}
int query(int pos){
    int s=-INF;
    while (pos)
    {
        check_max(s,tree[pos]);
        pos-=pos&-pos;
    }
    return s;
}
void f1(int l1,int r1,int l2,int r2){
    int N=r2-l1+1;
    rb(i,0,N) tree[i]=-INF;
    vector<LL> tmp;
    rb(i,l1,r2){
        tmp.PB((c[i]=-a[i]+1ll*t[i]*v));
    }
    sort(ALL(tmp));
    tmp.erase(unique(ALL(tmp)),tmp.end());
    vector<mp> pos;
    rb(i,l1,r2) pos.PB(II(a[i],i)),c[i]=lower_bound(ALL(tmp),c[i])-tmp.begin()+1;
    sort(ALL(pos));
    for(auto it:pos){
        if(it.second<=r1){
            chkmax(c[it.second],dp[it.second]);
        }
        else check_max(dp[it.second],query(c[it.second])+1);
    }
}
void f2(int l1,int r1,int l2,int r2){
    int N=r2-l1+1;
    rb(i,0,N) tree[i]=-INF;
    vector<LL> tmp;
    rb(i,l1,r2){
        tmp.PB((c[i]=a[i]+1ll*t[i]*v));
    }
    sort(ALL(tmp));
    tmp.erase(unique(ALL(tmp)),tmp.end());
    vector<mp> pos;
    rb(i,l1,r2) pos.PB(II(a[i],-i)),c[i]=lower_bound(ALL(tmp),c[i])-tmp.begin()+1;
    sort(ALL(pos));
    reverse(ALL(pos));
    for(auto it:pos){
        it.second*=-1;
        if(it.second<=r1){
            chkmax(c[it.second],dp[it.second]);
        }
        else check_max(dp[it.second],query(c[it.second])+1);
    }
}
void solve(int l,int r){
    if(l==r){
        return ;
    }
    int mid=(l+r)>>1;
    solve(l,mid);
    f1(l,mid,mid+1,r);
    f2(l,mid,mid+1,r);
    solve(mid+1,r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>v;
    n++;
    t[1]=0;
    a[1]=0;
    rb(i,2,n) cin>>t[i];
    rb(i,2,n) cin>>a[i];
    rb(i,1,n) dp[i]=-INF;
    dp[1]=0;
    solve(1,n);
    cout<<*max_element(dp+1,dp+1+n)<<endl;
    return 0;
}
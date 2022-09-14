#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const long long mod=998244353ll;
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return (a*binpow(a,b-1ll))%mod;
    else return binpow((a*a)%mod,b/2ll);
}
ll div1(ll a,ll b){
    return (a*binpow(b,mod-2ll))%mod;
}
ll p[300001];
bool check_point[300001];
struct node{
    ll molt;
    ll val;
};
node t[1400001];
node marge(node l,node r){
    if (l.val==-1) return r;
    if (r.val==-1) return l;
    node res;
    res.molt=(l.molt*r.molt)%mod;
    res.val=(l.val+(r.val*l.molt)%mod)%mod;
    return res;
}
node empt;
void build(int v,int l,int r){
    if (l>r) return;
    if (l==r){
        t[v].val=1ll;
        t[v].molt=p[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=marge(t[v+v],t[v+v+1]);
}
node get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return empt;
    if (l>=L && r<=R) {
        return t[v];
    }
    int m=(l+r)/2;
    return marge(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
int32_t main()
{
    empt.val=-1;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>p[i],p[i]=div1(p[i],100ll);
    build(1,1,n);
    set<int>st;
    st.insert(1);
    st.insert(n+1);
    node cur;
    cur=get(1,1,n,1,n);
    ll sum=div1(cur.val,cur.molt);
    /*cout<<(cur.val*4ll)%mod<<endl;
    <<sum<<endl;*/
    while (m--){
        int pos;cin>>pos;
        if (st.find(pos)==st.end()){
            auto it=st.lower_bound(pos);
            int nxt=(*it);
            it--;
            int last=(*it);
            cur=get(1,1,n,last,nxt-1);
            sum+=mod-div1(cur.val,cur.molt);
            sum%=mod;
            cur=get(1,1,n,last,pos-1);
            sum+=div1(cur.val,cur.molt);
            sum%=mod;
            cur=get(1,1,n,pos,nxt-1);
            sum+=div1(cur.val,cur.molt);
            sum%=mod;
            st.insert(pos);
        } else {
            st.erase(pos);
            auto it=st.lower_bound(pos);
            int nxt=(*it);
            it--;
            int last=(*it);
            cur=get(1,1,n,last,nxt-1);
            sum+=div1(cur.val,cur.molt);
            sum%=mod;
            cur=get(1,1,n,last,pos-1);
            sum+=mod-div1(cur.val,cur.molt);
            sum%=mod;
            cur=get(1,1,n,pos,nxt-1);
            sum+=mod-div1(cur.val,cur.molt);
            sum%=mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}
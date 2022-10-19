#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 320'000
#define ls (x<<1)
#define rs (x<<1|1)

const LL mod=998244353;
void upd(LL &x,LL y){x=(x+y)%mod;}
struct node{
    LL f[3][2];
    node(){memset(f,0,sizeof f);}
    void set(LL k){
        memset(f,0,sizeof f);
        f[2][k]=1;
        for (LL i:{0,1}){
            ++f[i][i|k];
            ++f[i][i^k];
            ++f[i][i&k];
        }
    }
    node operator + (const node &p) const{
        node ret;
        for (LL i:{0,1,2}){
            for (LL j:{0,1}){
                for (LL k:{0,1}){
                    upd(ret.f[i][k],f[i][j]*p.f[j][k]);
                }
            }
        }
        return ret;
    }
}seg[N<<2];
LL n,now[N];
vector<LL> q[N];

void mdf(LL x,LL l,LL r,LL t,LL k){
    if (l==r){
        seg[x].set(k);
        return;
    }
    LL mid=(l+r)>>1;
    if (t<=mid) mdf(ls,l,mid,t,k);
    if (t>mid) mdf(rs,mid+1,r,t,k);
    seg[x]=seg[ls]+seg[rs];
}
void build(LL x,LL l,LL r){
    if (l==r){
        seg[x].set(0);
        return;
    }
    LL mid=(l+r)>>1;
    build(ls,l,mid); build(rs,mid+1,r);
    seg[x]=seg[ls]+seg[rs];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (LL i=1;i<=n;++i){
        LL x,y; cin>>x>>y;
        q[x].push_back(i);
        q[y+1].push_back(i);
    }
    LL m=300000;
    build(1,1,n);
    LL ans=0;
    for (LL i=0;i<=m;++i){
        for (LL x:q[i]){
            mdf(1,1,n,x,now[x]^=1);
        }
        upd(ans,seg[1].f[2][1]);
    }
    cout<<ans<<'\n';
}
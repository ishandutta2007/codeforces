#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
const int MAXM = 17;

int n;
int p[MAXN],w[MAXN];
int mn[MAXM+1][MAXN];
int pc[MAXN];

int lc[86700001],rc[86700001],sm[86700001],tot;

inline void update(int &x,int l,int r,int p,int d){
    if(!x) x = ++tot;
    if(l == r){
        sm[x] += d;return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) update(lc[x],l,mid,p,d);
    else update(rc[x],mid+1,r,p,d);
    sm[x] = sm[lc[x]]+sm[rc[x]];
}

inline int query(int x,int l,int r,int L,int R){
    if(L > R) return 0;
    if(!x) return 0;
    if(l == L && r == R) return sm[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return query(lc[x],l,mid,L,R);
    if(L > mid) return query(rc[x],mid+1,r,L,R);
    return query(lc[x],l,mid,L,mid)+query(rc[x],mid+1,r,mid+1,R);
}

inline int calc(int l,int r){
    int c = pc[r-l+1];
    if(w[mn[c][l]] <= w[mn[c][r-(1<<c)+1]]) return mn[c][l];
    return mn[c][r-(1<<c)+1];
}

int ch[MAXN<<1][2],R,rt[MAXN<<1],fa[MAXN<<1];
int tl[MAXN<<1],tr[MAXN<<1];

inline int work(int l,int r,int L,int R){
    if(l > r){
        tl[n-1+L] = tr[n-1+L] = L;
        return n-1+L;
    }
    int mid = calc(l,r);tl[mid] = L;tr[mid] = R;
    ch[mid][0] = work(l,mid-1,L,mid);
    ch[mid][1] = work(mid+1,r,mid+1,R);
    fa[ch[mid][0]] = fa[ch[mid][1]] = mid;
    return mid;
}

LL now = 0;
LL f[MAXN];

inline void dfs(int v){
    if(v >= n) return;
    FOR(i,tl[ch[v][0]],tr[ch[v][0]]) f[v] += query(rt[ch[v][1]],1,n,1,p[i]-1);
    dfs(ch[v][0]);dfs(ch[v][1]);
}

inline LL calc(int x){
    int lc = ch[x][0],rc = ch[x][1];
    return std::min(1ll*(tr[lc]-tl[lc]+1)*(tr[rc]-tl[rc]+1)-f[x],f[x]);
}

inline void upd(int x,int p,int d){
    x += n-1;update(rt[x],1,n,p,d);
    int las = x;x = fa[x];
    while(x){
        now -= calc(x);
        bool o = ch[x][1]==las;
        update(rt[x],1,n,p,d);
        if(o == 0){
            f[x] += d*query(rt[ch[x][1]],1,n,1,p-1);
        }
        else{
            f[x] += d*query(rt[ch[x][0]],1,n,p+1,n);
        }
        now += calc(x);
        las = x;x = fa[x];
    }
}

int main(){
    pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",p+i);
    FOR(i,1,n-1) scanf("%d",w+i),mn[0][i] = i;
    FOR(i,1,MAXM){
        for(int j = 1;j+(1<<(i-1)) < n;++j){
            if(w[mn[i-1][j]] < w[mn[i-1][j+(1<<(i-1))]])
                mn[i][j] = mn[i-1][j];
            else mn[i][j] = mn[i-1][j+(1<<(i-1))];
        }
    }
    R = work(1,n-1,1,n);
    FOR(i,1,n){
        int v = n-1+i;
        while(v) update(rt[v],1,n,p[i],1),v = fa[v];
    }
    dfs(R);
    FOR(i,1,n-1) now += calc(i);
    int q;scanf("%d",&q);
    FOR(ccc,1,q){
        int x,y;scanf("%d%d",&x,&y);
        upd(x,p[x],-1);upd(x,p[y],1);
        upd(y,p[y],-1);upd(y,p[x],1);
        std::swap(p[x],p[y]);
        printf("%lld\n",now);
    }
    return 0;
}
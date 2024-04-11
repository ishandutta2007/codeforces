#include<bits/stdc++.h>

#define fi first
#define se second
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
int n,k,d;
int a[MAXN],p[MAXN];
std::map<int,int> S1,S2;

LL mn[MAXN<<2],tag[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void pushup(int x){
    mn[x] = std::min(mn[lc],mn[rc]);
}

inline void cover(int x,LL d){
    mn[x] += d;tag[x] += d;
}

inline void pushdown(int x){
    if(tag[x]){
        cover(lc,tag[x]);
        cover(rc,tag[x]);
        tag[x] = 0;
    }
}

inline void modify(int x,int l,int r,int L,int R,LL d){
    if(L > R) return;
    if(l == L && r == R) {cover(x,d);return;}
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    pushup(x);
}

inline int query(int x,int l,int r,int L,int R,LL k){
    if(L > R) return -1;
    if(mn[x] > k) return -1;
    if(l == r) return l;
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) return query(lc,l,mid,L,R,k);
    if(L > mid) return query(rc,mid+1,r,L,R,k);
    int t = query(lc,l,mid,L,mid,k);
    if(t == -1) return query(rc,mid+1,r,mid+1,R,k);
    return t;
}

inline int calc(int x,int l,int r,int p){
    if(l == r) return mn[x];
    int mid = (l + r) >> 1;pushdown(x);
    if(p <= mid) return calc(lc,l,mid,p);
    else return calc(rc,mid+1,r,p);
}

int st1[MAXN],st2[MAXN],tp1,tp2;
int b[MAXN];
// 1:max 2:min

inline int mod(int x){
    x %= d;x += d;x %= d;
    return x;
}

inline void gao(){
    int ans = -1,ansl = -1,ansr = -1;
    for(int l = 1,r = 1;r <= n;l = r+1,r = l){
        while(r < n && a[r+1]==a[l]) r++;
        if(ans < r-l+1 || (ans==r-l+1&&l<ansl)){
            ans = r-l+1;
            ansl = l;ansr = r;
        }
    }
    printf("%d %d\n",ansl,ansr);
    exit(0);
}

int main(){
    scanf("%d%d%d",&n,&k,&d);
    FOR(i,1,n) scanf("%d",a+i);
    if(d == 0) gao();
    FOR(i,1,n) b[i] = mod(a[i]);
    p[1] = 1;S1[b[1]]++;S2[a[1]]++;
    FOR(i,2,n){
        p[i] = p[i-1];S1[b[i]]++;S2[a[i]]++;
//        DEBUG(S2[2]);
        for(;p[i] < i && (S1[b[i]] != i-p[i]+1 || S2[a[i]] > 1);p[i]++) S1[b[p[i]]]--,S2[a[p[i]]]--;
    }
    FOR(i,1,n) modify(1,1,n,i,i,1ll*i*d);
    st1[tp1 = 1] = st2[tp2 = 1] = 1;
    int ans = 1,ansl = 1,ansr = 1;
    FOR(i,2,n){
        while(tp1 && a[st1[tp1]] <= a[i]){
            modify(1,1,n,st1[tp1-1]+1,st1[tp1],-a[st1[tp1]]);
            tp1--;
        }
        st1[++tp1] = i;
        modify(1,1,n,st1[tp1-1]+1,st1[tp1],a[i]);
        while(tp2 && a[st2[tp2]] >= a[i]){
            modify(1,1,n,st2[tp2-1]+1,st2[tp2],a[st2[tp2]]);
            tp2--;
        }
        st2[++tp2] = i;
        modify(1,1,n,st2[tp2-1]+1,st2[tp2],-a[i]);
        int t = query(1,1,n,p[i],i,1ll*(k+i)*d);
        if(t != -1){
            if(ans < i-t+1 || (ans==i-t+1 && ansl > t)){
                ans = i-t+1;
                ansl = t;ansr = i;
            }
        }
  //      if(i == 5) DEBUG(calc(1,1,n,2));
    }
    printf("%d %d\n",ansl,ansr);
    return 0;
}
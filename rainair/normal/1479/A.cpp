#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 5;
int a[MAXN],n;
inline void query(int x){
    if(x == 0 || x == n+1) return;
    if(a[x]) return;
    printf("? %d\n",x);std::fflush(stdout);
    scanf("%d",a+x);
}

inline void answer(int x){
    int ans = 0;
    FOR(i,1,n) if(a[i] == x) ans = i;
    printf("! %d\n",ans);
    std::fflush(stdout);
    exit(0);
}

inline void work(int l,int r){
    if(r-l+1 == 1){
        query(l);
        answer(a[l]);
        return;
    }
    if(r-l+1 == 2){
        query(l);query(r);
        if(a[l] < a[r]) answer(a[l]);
        else answer(a[r]);
        return;
    }
    if(r-l+1 == 3){
        query(l);query(l+1);query(l+2);
        if(a[l+1] < a[l] && a[l+1] < a[l+2]) answer(a[l+1]);
        else if(a[l+1] > a[l]) answer(a[l]);
        else answer(a[l+2]);
        return;
    }
    int mid = (l + r) >> 1;
    query(mid);query(mid+1);
    if(a[mid+1] > a[mid]) work(l,mid);
    else work(mid+1,r);
}

int main(){
    scanf("%d",&n);
    a[0] = a[n+1] = 1e9;
    query(1);query(n);
    work(1,n);
    return 0;
}
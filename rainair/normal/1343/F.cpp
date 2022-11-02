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

const int MAXN = 200+5;

int n;
int a[MAXN];
std::bitset<MAXN> b[MAXN];
bool used[MAXN];
int l[MAXN];
int p[MAXN][MAXN];
std::bitset<MAXN> pre[MAXN];

inline bool work(){
//    if(!(a[1]==3&&a[2]==1)) return 0;
    FOR(i,1,n) pre[i].reset();
    pre[1][a[1]] = pre[1][a[2]] = 1;pre[2][a[2]] = 1;
    FOR(i,3,n){
        int ps = -1;
        FOR(j,1,n-1){
            if(used[j]) continue;
            if(l[j] > i) continue;
            std::bitset<MAXN> t = pre[i-l[j]+1]&b[j];
            if(t.count() == l[j]-1){
                ps = j;break;
            }
        }
        if(ps == -1) return 0;
        used[ps] = 1;
        FOR(j,1,n) if(!pre[1][j] && b[ps][j]){a[i] = j;break;}
        FOR(j,1,i) pre[j][a[i]] = 1;
//        DEBUG(a[i]);
    }
    FOR(i,1,n) printf("%d ",a[i]);puts("");
    return 1;
}

inline void Solve(){
    scanf("%d",&n);CLR(p,0);
    FOR(i,1,n-1){
        b[i].reset();
        scanf("%d",l+i);
        FOR(j,1,l[i]){
            scanf("%d",&p[i][j]);
            b[i].set(p[i][j]);
        }
    }
    FOR(i,1,n-1){
        if(l[i] == 2){
            FOR(j,1,n) used[j] = 0;
            a[1] = p[i][1];a[2] = p[i][2];
            used[i] = 1;
            if(work()) return;
            std::swap(a[1],a[2]);
            FOR(j,1,n) used[j] = 0;
            used[i] = 1;
            if(work()) return;
        }
    }
    assert(0);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}
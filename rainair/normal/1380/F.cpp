#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<LL,LL>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 5;
const int ha = 998244353;

inline void add(int &x,int y){
    (x += y);if(x >= ha) x-= ha;
}

struct Node{
    int a[2][2];
    Node(){CLR(a,0);}
    inline Node operator * (const Node &t) const {
        Node res;
        FOR(i,0,1){
            FOR(j,0,1){
                add(res.a[i][j],1ll*a[i][0]*t.a[0][j]%ha);
                add(res.a[i][j],1ll*a[i][1]*t.a[1][j]%ha);
            }
        }
        return res;
    }

    inline void print(){
        FOR(i,0,1) FOR(j,0,1) printf("%d%c",a[i][j]," \n"[j==1]);
    }
}sm[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)
inline void update(int x,int l,int r,int p,Node d){
    if(l == r){
        sm[x] = d;return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) update(lc,l,mid,p,d);
    else update(rc,mid+1,r,p,d);
    sm[x] = sm[rc]*sm[lc];
}

inline Node query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return sm[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return query(rc,mid+1,r,mid+1,R)*query(lc,l,mid,L,mid);
}

int n,m;
char str[MAXN];
int a[MAXN];
std::set<int> S;

inline int calc(){
//    DEBUG(S.size());
    if(S.empty()) return 1;
    int p = *S.rbegin();
    if(p == 1) return a[1]+1;
    Node t = query(1,1,n,2,p);
    return (1ll*t.a[0][0]*(a[1]+1)%ha+t.a[0][1])%ha;
}

int g[MAXN];

inline void upd(int i){
    Node t;t.a[0][0] = a[i]+1;t.a[1][0] = 1;t.a[1][1] = 0;
    if(a[i] == 1 && i > 1){
        t.a[0][1] = g[a[i-1]];
    }
    else t.a[0][1] = 0;
    update(1,1,n,i,t);
//    t.print();
}

int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    FOR(i,0,9) FOR(j,0,9) if(i+j >= 10) g[i+j-10]++;
    FOR(i,1,n) a[i] = str[i]-'0';
    std::reverse(a+1,a+n+1);
    FOR(i,1,n) if(a[i]) S.insert(i);
    FOR(i,1,n) upd(i);
    FOR(i,1,m){
        int x,d;scanf("%d%d",&x,&d);x = n-x+1;
        if(a[x]) S.erase(x);
        a[x] = d;
        if(a[x]) S.insert(x);
        upd(x);if(x != n) upd(x+1);
        printf("%d\n",calc());
    }
    return 0;
}
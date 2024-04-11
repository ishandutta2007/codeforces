#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3e5 + 5;
int n,m;LL t;
int ans[MAXN];

struct Node{
    int s,d,f,id;
    Node(int s=0,int d=0,int f=0,int id=0) : s(s),d(d),f(f),id(id) {}

    inline bool operator < (const Node &t) const {
        return s < t.s;
    }
}a[MAXN];

int id[MAXN];

int main(){
    scanf("%d%d%lld",&n,&m,&t);
    FOR(i,0,n-1){
        char str[23];
        scanf("%d%s",&a[i].s,str+1);
        --a[i].s;a[i].d = (str[1]=='L');
        a[i].s = (m-a[i].s)%m;
        a[i].f = a[i].d?(a[i].s+t%m):(a[i].s-t%m);
        a[i].f = (a[i].f%m+m)%m;a[i].id = i;
    }
    std::sort(a,a+n);
    // 'L' =  - d[i]=0
    // 'R' =  + d[i]=1
    int id = 0;
    FOR(i,1,n-1){
        if(a[0].d^a[i].d){
            int len = a[0].d?a[i].s-a[0].s:a[0].s-a[i].s;
            if(len < 0) len += m; 
            //   2 
            if(t < (len+1)/2) continue;
            if(m&1){
                LL tt = t;tt -= (len+1)/2;(id += 1) %= n;
                if(tt < m/2) continue;
                if(len&1) tt -= (m/2),(id += 1) %= n;
                (id += (tt/m)*2%n) %= n;tt %= m;
                if(tt >= m/2) (id += 1) %= n;
            }
            else (id += ((t-(len+1)/2)/(m/2)+1)%n) %= n;
        }
    }
    if(!a[0].d) id = (n-id)%n;
    std::vector<int> S;FOR(i,0,n-1) S.pb(a[i].f);
    std::sort(all(S));int tp = -1;
    if(!a[0].d) {FOR(i,0,SZ(S)-1) if(S[i] == a[0].f){tp = i;break;}}
    else {ROF(i,SZ(S)-1,0) if(S[i] == a[0].f){tp = i;break;}}
    int tt = tp;
    do{
        ans[a[id].id] = S[tp];
        (tp += 1) %= n;
        (id += 1) %= n;
    }while(tp != tt);
//    FOR(i,0,n-1) DEBUG(ans[i]);
    FOR(i,0,n-1) printf("%d%c",(m-ans[i])%m+1," \n"[i==n-1]);
    return 0;
}
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

const int MAXN = 1e6 + 5;
const int ha = 1e9 + 7;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

int n,m;
int f[MAXN];

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

struct Node{
    int a[2][2];
    Node(){CLR(a,0);}
    inline Node operator * (const Node &t) const {
        Node res;
        FOR(i,0,1) FOR(j,0,1){
            LL x=0;
            FOR(k,0,1) x += (LL)a[i][k]*t.a[k][j];
            res.a[i][j] = x%ha;
        }
        return res;
    }
};

inline Node qpow(Node a,int n){
    Node res;res.a[0][0] = res.a[1][1] = 1;
    while(n){
        if(n&1) res = res*a;
        a = a*a;
        n >>= 1;
    }
    return res;
}

int main(){
    scanf("%d%d",&n,&m);
    Node A;
    A.a[1][0] = 1;
    A.a[0][0] = 3ll*m-1;
    A.a[0][1] = (ha-2ll*m*m%ha+m)%ha;
    A = qpow(A,n-1);
    int ans = 1ll*A.a[0][0]*(3*m-1)%ha;
    add(ans,A.a[0][1]);
    (ans += ha-qpow(m,n)) %= ha;
    ans = 1ll*ans*m%ha*qpow(2*m-1)%ha;
    (ans += qpow(m,n)) %= ha;
    printf("%d\n",ans);
    return 0;
}
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
const int ha = 998244353;

inline int add(int x,int y){
    (x += y);if(x >= ha) x -= ha;return x;
//    (x += y) %= ha;return x;
}

struct Poly{//af[1]+b
    int a,b;
    Poly(int a=0,int b=0) : a(a),b(b) {}
    inline Poly operator + (const Poly &t) const {
        return Poly(add(a,t.a),add(b,t.b));
    }
    inline Poly operator + (const int &x) const {
        return Poly(a,add(b,x));
    }
    inline Poly operator * (const int &x) const {
        return Poly(1ll*a*x%ha,1ll*b*x%ha);
    }
};

struct Node{
    int a[3][3];
    Node(){CLR(a,0);}
    Node operator * (const Node &t) const {
        Node res;
        FOR(i,0,2){
            FOR(j,0,2){
                FOR(k,0,2){
                    res.a[i][j] = add(res.a[i][j],1ll*a[i][k]*t.a[k][j]%ha);
                }
            }
        }
        return res;
    }
    inline void print(){
        FOR(i,0,2) FOR(j,0,2) printf("%d%c",a[i][j]," \n"[j==2]);
    }
}sm[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)
int p[MAXN],invp[MAXN];

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

bool is[MAXN];

inline void build(int x,int l,int r){
    if(l == r){
        Node A;A.a[2][2] = 1;
        if(is[l-1]){
            A.a[0][0] = 1;A.a[0][2] = ha-invp[l-1];
        }
        else{
            A.a[0][0] = invp[l-1];
            A.a[0][1] = add(1,ha-invp[l-1]);
            A.a[0][2] = ha-invp[l-1];
        }
        if(is[l]){
            FOR(i,0,2) A.a[1][i] = A.a[0][i];
        }
        else{
            A.a[1][1] = 1;
        }
        sm[x] = A;
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    sm[x] = sm[rc]*sm[lc];
}

inline void update(int x,int l,int r,int p){
    if(l == r){
        Node A;A.a[2][2] = 1;
        if(is[l-1]){
            A.a[0][0] = 1;A.a[0][2] = ha-invp[l-1];
        }
        else{
            A.a[0][0] = invp[l-1];
            A.a[0][1] = add(1,ha-invp[l-1]);
            A.a[0][2] = ha-invp[l-1];
        }
        if(is[l]){
            FOR(i,0,2) A.a[1][i] = A.a[0][i];
        }
        else{
            A.a[1][1] = 1;
        }
        sm[x] = A;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) update(lc,l,mid,p);
    else update(rc,mid+1,r,p);
    sm[x] = sm[rc]*sm[lc];
}

int n,q;

int main(){
    //srand(20050117);
    scanf("%d%d",&n,&q);
    //n = q = 200000;
    int inv = qpow(100);
    FOR(i,1,n) scanf("%d",p+i),p[i] = 1ll*p[i]*inv%ha,invp[i] = qpow(p[i]);
    //FOR(i,1,n) p[i] = 1+rand()%100,p[i] = 1ll*p[i]*inv%ha,invp[i] = qpow(p[i]);
    is[1] = 1;
    build(1,2,n+1);
    FOR(i,1,q){
        int x;scanf("%d",&x);
        //int x = 2+rand()%(n-1);
        Node A;
        is[x] ^= 1;
        update(1,2,n+1,x);
        update(1,2,n+1,x+1);
//        sm[1].print();
        Poly ans;
        ans = ans+Poly(1,0)*sm[1].a[0][0];
        ans = ans+Poly(1,0)*sm[1].a[0][1];
        ans = ans+sm[1].a[0][2];
        int res = ha-ans.b;
        res = 1ll*res*qpow(ans.a)%ha;
        printf("%d\n",res);
    }
    return 0;
}
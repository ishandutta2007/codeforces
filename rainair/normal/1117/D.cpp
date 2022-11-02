#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define lc (x<<1)
#define se second
#define U unsigned
#define rc (x<<1|1)
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
#define int LL

inline int read() {
    int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';return x*f;
}

const int mod = 1e9 + 7;
const int N = 105;

LL n, m;

struct Node {
	LL a[N][N];
	Node(){
        CLR(a,0);
    }
};
Node operator * (const Node &A,const Node &B) {
	Node C;
	FOR(k,1,m)FOR(i,1,m)FOR(j,1,m)C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j] % mod) % mod;
	return C;
}

Node ksm(Node A,LL b){
	Node res;FOR(i,1,m) res.a[i][i] = 1;while(b){if(b & 1) res = res * A;A = A * A;b >>= 1;}return res;
}

signed main() {
	scanf("%I64d%I64d",&n,&m);
	if (n < m){puts("1");return 0;}
	if (n == m){puts("2");return 0;}
	Node A;A.a[1][1] = A.a[1][m] = 1;FOR(i,2,m) A.a[i][i - 1] = 1;A = ksm(A,n-m);LL Ans = 0;Ans += A.a[1][1] * 2 % mod;FOR(i,2,m) (Ans+=A.a[1][i]) %= mod;printf("%I64d\n",Ans%mod);
    return 0;
}
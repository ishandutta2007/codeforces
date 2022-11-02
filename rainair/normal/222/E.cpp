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

const int MAXN = 52;
const int ha = 1e9 + 7;

inline void add(int &x,int y){
	x += y;if(x >= ha) x -= ha;
}
int m;
struct Node{
	int a[MAXN+1][MAXN+1];
	
	friend Node operator * (const Node &A,const Node &B){
		Node res;CLR(res.a,0);
		FOR(i,1,m){
			FOR(j,1,m){
				FOR(k,1,m){
					add(res.a[i][j],1ll*A.a[i][k]*B.a[k][j]%ha);
				}
			}
		}
		return res;
	}
};

inline Node qpow(Node a,LL n){
	Node res;FOR(i,1,m) res.a[i][i] = 1;
	while(n){
		if(n&1) res = res*a;
		a = a*a;
		n>>=1;
	}
	return res;
}

LL n;int k;
// f[i][j] ij

inline int ctoi(char x){
	if(x <= 'Z') return 26+x-'A'+1;
	return x-'a'+1;
}

int main(){
	scanf("%lld%d%d",&n,&m,&k);
	Node A;
	FOR(i,1,m){
		FOR(j,1,m){
			A.a[i][j] = 1;
		}
	}
	FOR(i,1,k){
		char str[23];scanf("%s",str+1);
		int x = ctoi(str[1]),y = ctoi(str[2]);
		A.a[x][y] = 0;//DEBUG(x);DEBUG(y);
	}
	A = qpow(A,n-1);
	int ans = 0;
	FOR(i,1,m)FOR(j,1,m) add(ans,A.a[i][j]);
	printf("%d\n",ans);
	return 0;
}
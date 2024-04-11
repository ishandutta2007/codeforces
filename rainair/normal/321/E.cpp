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

inline char nc(){
	#define SIZE 1000000+3
	static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
	if(p1 == p2){
		p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
		if(p1 == p2) return -1;
	}
	return *p1++;
	#undef SIZE
}

template <typename T>
inline void read(T &x){
	x = 0;int flag = 0;char ch = nc();
	while(!isdigit(ch)){
		if(ch == '-') flag = 1;
		ch = nc();
	}
	while(isdigit(ch)){
		x = (x<<1) + (x<<3) + (ch^'0');
		ch = nc();
	}
	if(flag) x = -x;
}

const int MAXN = 4000+5;
int a[MAXN][MAXN];
int n,k;
int f[2][MAXN],now;

inline int calc(int i,int j){
	return a[j][j]-a[i-1][j]-a[j][i-1]+a[i-1][i-1];
}

inline void work(int l,int r,int L,int R){
	if(l > r) return;
	if(L == R){
		FOR(i,l,r) f[now][i] = f[now^1][L]+calc(L+1,i);
		return;
	}
	int mid = (l + r) >> 1,ps = -1;
	FOR(i,L,std::min(R,mid-1)){
		if(f[now][mid] > f[now^1][i]+calc(i+1,mid)){
			f[now][mid] = f[now^1][i]+calc(i+1,mid);
			ps = i;
		}
	}
//	DEBUG(mid);
	work(l,mid-1,L,ps);work(mid+1,r,ps,R);
}

int main(){
//	freopen("../TestData/a.in","r",stdin);
	read(n);read(k);
	FOR(i,1,n) FOR(j,1,n) read(a[i][j]);
	FOR(i,1,n) FOR(j,1,n) a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	CLR(f[now],0x3f);f[now][0] = 0;
//	DEBUG(calc(3,5));DEBUG(a[5][5]);DEBUG(a[2][5]);DEBUG(a[5][2]);DEBUG(a[2][2]);
	FOR(i,1,k){
		now ^= 1;CLR(f[now],0x3f);
		work(i,n,i-1,n);
//		FOR(j,i,n) printf("%d ",f[now][j]);puts("");
	}
	printf("%d\n",f[now][n]/2);
	return 0;
}
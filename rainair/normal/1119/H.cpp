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

int N;
const int MAXN = 2e5 + 5;
const int ha = 998244353;
const int inv2 = 499122177;
const int inv4 = 748683265;

inline int qpow(LL a,int n=ha-2){
	a = (a%ha+ha)%ha;
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

inline void FWT(int f[]){
	for(int mid = 1;mid < N;mid <<= 1){
		for(int i = 0;i < N;i += (mid<<1)){
			FOR(j,0,mid-1){
				int x = f[i+j],y = f[i+mid+j];
				f[i+j] = (x+y)%ha;f[i+mid+j] = (x+ha-y)%ha;
			}
		}
	}
}

inline void iFWT(int f[]){
	for(int mid = N>>1;mid;mid >>= 1){
		for(int i = 0;i < N;i += (mid<<1)){
			FOR(j,0,mid-1){
				int x=  f[i+j],y = f[i+mid+j];
				f[i+j] = 1ll*(x+y)*inv2%ha;f[i+mid+j] = 1ll*(x+ha-y)*inv2%ha;
			}
		}
	}
}

int n,k;
int a[MAXN],b[MAXN],c[MAXN];
int sm = 0;
int f1[MAXN],f2[MAXN],f3[MAXN],ans[MAXN];

int main(){
	scanf("%d%d",&n,&k);N = 1<<k;
	int x,y,z;scanf("%d%d%d",&x,&y,&z);
	x %= ha;y %= ha;z %= ha;
	FOR(i,1,n){
		scanf("%d%d%d",a+i,b+i,c+i);
		sm ^= a[i];b[i] ^= a[i];c[i] ^= a[i];a[i] = 0;
		++f1[b[i]];++f2[c[i]];++f3[b[i]^c[i]];
	}
	FWT(f1);FWT(f2);FWT(f3);
	FOR(i,0,N-1){
		LL p1 = f1[i],p2 = f2[i],p3 = f3[i];
		LL c1 = 1ll*(n+p1+p2+p3)%ha*inv4%ha;
		LL t = 2ll*c1%ha;t = ha-t;
		LL c2 = 1ll*(n+p1+t)%ha*inv2%ha;
		LL c3 = 1ll*(n+p2+t)%ha*inv2%ha;
		LL c4 = 1ll*(n+p3+t)%ha*inv2%ha;
		ans[i] = 1ll*qpow(x+y+z,c1)*qpow(x+y-z,c2)%ha*qpow(x-y+z,c3)%ha*qpow(x-y-z,c4)%ha;
	}
	iFWT(ans);
	FOR(i,0,N-1) printf("%d ",ans[i^sm]);
	return 0;
}
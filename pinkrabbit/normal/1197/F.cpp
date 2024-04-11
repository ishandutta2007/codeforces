#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define ff(i) for(int i=0;i<64;++i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define ll long long
#define mod 998244353
#define MN 1005
#define fi first
#define se second
#define mp std::make_pair
typedef std::pair<int,int> pii;
struct mat{
	int a[64][64];
	mat(){}
	mat(int t){ff(i)ff(j)a[i][j]=i==j?t:0;}
	inline friend mat operator+(const mat&a,const mat&b){mat c;ff(i)ff(j)c.a[i][j]=(a.a[i][j]+b.a[i][j])%mod;return c;}
	inline friend mat operator*(const mat&a,const mat&b){mat c(0);ff(i)ff(j)ff(k)c.a[i][j]=(c.a[i][j]+(ll)a.a[i][k]*b.a[k][j])%mod;return c;}
	inline friend mat operator^(mat a,int b){mat c(1);for(;b;b>>=1,a=a*a)if(b)c=c*a;return c;}
};
struct vec{
	int a[64];
	vec(){ff(i)a[i]=0;}
	inline friend vec operator*(const mat&a,const vec&b){vec c;ff(i)ff(j)c.a[i]=(c.a[i]+(ll)a.a[i][j]*b.a[j])%mod;return c;}
};
int n,a[MN],m;
vector<pii>v[MN];
int f[4];mat A[4];
mat se[30];
inline void trans(vec&a,const int&b){for(int j=0;j<=29;++j)if(b>>j&1)a=se[j]*a;}
int fin[MN][4];
int ans[4],tmp[4];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	scanf("%d",&m);
	F(i,1,m){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		v[x].push_back(mp(y,c));
	}
	F(i,1,n)sort(v[i].begin(),v[i].end());
	F(i,1,3){
		F(j,1,3)scanf("%d",&f[j]);
		ff(s){
			int s1=s&3,s2=s>>2&3,s3=s>>4&3,v[4],k=0;
			F(j,0,3)v[j]=0;
			if(f[1])v[s1]=1;
			if(f[2])v[s2]=1;
			if(f[3])v[s3]=1;
			while(v[k])++k;
			int ns=(s2<<4)|(s1<<2)|k;
			A[i].a[ns][s]=1;
		}
	}
	se[0]=A[1]+A[2]+A[3];
	F(i,1,29)se[i]=se[i-1]*se[i-1];
	ans[0]=1;
	F(i,1,n){
		vec vi;
		vi.a[63]=1;
		int lst=0;
		for(auto e:v[i]){
			int pos=e.fi,col=e.se;
			trans(vi,pos-lst-1);
			if(col==1)vi=A[1]*vi;
			if(col==2)vi=A[2]*vi;
			if(col==3)vi=A[3]*vi;
			lst=pos;
		}
		trans(vi,a[i]-lst);
		ff(s)fin[i][s&3]=(fin[i][s&3]+vi.a[s])%mod;
		std::swap(ans,tmp);
		F(j,0,3){
			ans[j]=0;
			F(k,0,3)ans[j]=(ans[j]+(ll)tmp[k]*fin[i][j^k])%mod;
		}
	}
	printf("%d\n",ans[0]);
	return 0;
}
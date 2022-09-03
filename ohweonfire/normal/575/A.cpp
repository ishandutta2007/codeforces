// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=50111;
int mod;
struct matrix
{
	int a[2][2];
	matrix(){memset(a,0,sizeof(a));}
	matrix(int k1,int k2)
	{
		a[0][0]=k1%mod;
		a[0][1]=k2%mod;
		a[1][0]=1;
		a[1][1]=0;
	}
	matrix(int k1,int k2,int k3,int k4)
	{
		a[0][0]=k1;
		a[0][1]=k2;
		a[1][0]=k3;
		a[1][1]=k4;
	}
};
matrix operator *(const matrix&x,const matrix&y)
{
	matrix z;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)z.a[i][j]=(z.a[i][j]+(LL)x.a[i][k]*y.a[k][j])%mod;
	return z;
}

namespace sgt
{
	matrix a[maxn<<2];
	void prework(matrix*v,int l,int r,int t)
	{
		if(l==r)
		{
			a[t]=v[l];
			return;
		}
		int mid=(l+r)/2;
		prework(v,l,mid,t*2);
		prework(v,mid+1,r,t*2+1);
		a[t]=a[t*2+1]*a[t*2];
	}
	matrix query(int l,int r,int tl,int tr,int t)
	{
		if(l<=tl&&tr<=r)return a[t];
		int mid=(tl+tr)/2;
		if(r<=mid)return query(l,r,tl,mid,t*2);
		else if(l>mid)return query(l,r,mid+1,tr,t*2+1);
		else return query(l,r,mid+1,tr,t*2+1)*query(l,r,tl,mid,t*2);
	}
}

int n,m,s[maxn],val[maxn];
LL k,pos[maxn];

map<LL,int> M;
set<LL> modified;
int getv(LL p){if(M.find(p)!=M.end())return M[p];else return s[p%n];}
matrix get_tran(LL p){return matrix(getv(p-1),getv(p-2));}
matrix mat[maxn],mat_pre[maxn],mat_suf[maxn];

matrix qpow(matrix x,LL y)
{
	matrix ret;ret.a[0][0]=ret.a[1][1]=1;
	while(y)
	{
		if(y&1)ret=ret*x;
		x=x*x;
		y>>=1;
	}
	return ret;
}
matrix calc_reg(LL l,LL r)
{
	if(l/n==r/n)return sgt::query(l%n,r%n,0,n-1,1);
	else return mat_pre[r%n]*qpow(mat_suf[0],r/n-l/n-1)*mat_suf[l%n];
}

matrix calc_tran(LL l,LL r)// [l,r]
{
	matrix ret;ret.a[0][0]=1;
//	for(int i=l;i<=r;i++)ret=get_tran(i)*ret;return ret;
	while(l<=r)
	{
		if(modified.size()==0||*modified.begin()>r)
		{
			ret=calc_reg(l,r)*ret;
			break;
		}
		LL v=*modified.begin();
		if(v>l)ret=calc_reg(l,v-1)*ret;
		ret=get_tran(v)*ret;
		l=v+1;
		modified.erase(modified.begin());
	}
	return ret;
}

int main()
{
	get2(k,mod);get1(n);
	for(int i=0;i<n;i++)get1(s[i]);
	get1(m);
	
	for(int i=0;i<m;i++)
	{
		get2(pos[i],val[i]);
		M[pos[i]]=val[i];
		modified.insert(pos[i]+1);
		modified.insert(pos[i]+2);
	}
	
	if(mod==1)
	{
		puts("0");
		return 0;
	}
	if(k<2)
	{
		printendl(k);
		return 0;
	}
	
	for(int i=0;i<n;i++)mat[i]=matrix(s[(i+n-1)%n],s[(i+n+n-2)%n]);
	
	mat_pre[0]=mat[0];
	for(int i=1;i<n;i++)mat_pre[i]=mat[i]*mat_pre[i-1];
	mat_suf[n-1]=mat[n-1];
	for(int i=n-2;i>=0;i--)mat_suf[i]=mat_suf[i+1]*mat[i];
	sgt::prework(mat,0,n-1,1);
	
	printf("%d\n",calc_tran(2,k).a[0][0]);
	return 0;
}
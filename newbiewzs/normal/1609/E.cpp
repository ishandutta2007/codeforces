#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define fl fflush(stdout)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
const int N=1e5+5;
const int inf=1e9;
int n,q;
char a[N],c[2];
int op;
struct Matrix{
	int s[3][3];
	friend Matrix operator * (Matrix x,Matrix y){
		Matrix z;
		for(int i=0;i<=2;i++){
			for(int k=0;k<=2;k++){
				z.s[i][k]=inf;
				for(int j=0;j<=2;j++){
					z.s[i][k]=min(z.s[i][k],x.s[i][j]+y.s[j][k]);
				}
			}
		}
		return z;
	} 
}summ[N*4],A,B,C,pre,ans;
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
void update(int u){
	summ[u]=summ[ls]*summ[rs];
}
void build(int u,int l,int r){
	if(l==r){
		if(a[l]=='a')summ[u]=A;
		if(a[l]=='b')summ[u]=B;
		if(a[l]=='c')summ[u]=C;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(u);
}
void add(int u,int l,int r,int x){
	if(l==r){
		if(a[l]=='a')summ[u]=A;
		if(a[l]=='b')summ[u]=B;
		if(a[l]=='c')summ[u]=C;
		return ;
	}
	if(x<=mid)add(ls,l,mid,x);
	else add(rs,mid+1,r,x);
	update(u);
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();q=read();
	scanf("%s",a+1);
	
	for(int i=0;i<=2;i++)for(int k=0;k<=2;k++)pre.s[i][k]=0;
	pre.s[0][1]=pre.s[0][2]=inf;
	A.s[0][0]=1;A.s[0][1]=0;A.s[0][2]=0;
	A.s[1][0]=inf;A.s[1][1]=0;A.s[1][2]=0;
	A.s[2][0]=inf;A.s[2][1]=inf;A.s[2][2]=0;
	
	B.s[0][0]=0;B.s[0][1]=0;B.s[0][2]=0;
	B.s[1][0]=inf;B.s[1][1]=1;B.s[1][2]=0;
	B.s[2][0]=inf;B.s[2][1]=inf;B.s[2][2]=0;
	
	C.s[0][0]=0;C.s[0][1]=0;C.s[0][2]=0;
	C.s[1][0]=inf;C.s[1][1]=0;C.s[1][2]=0;
	C.s[2][0]=inf;C.s[2][1]=inf;C.s[2][2]=1;
	
	build(1,1,n);
	for(int i=1;i<=q;i++){
		op=read();scanf("%s",c+1);
		a[op]=c[1];
		add(1,1,n,op);
		ans=pre*summ[1];
		cout<<min(min(ans.s[0][0],ans.s[0][1]),ans.s[0][2])<<'\n';
	}
	return 0;
}
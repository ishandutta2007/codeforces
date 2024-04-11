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
//#define int long long
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
const int N=5e5+5;
int T,n,m,x,pa[N],pb[N],tmp[N],ha[N],hb[N],ans[N];
vi v[N],f[N],g[N];
struct node{
	int val,id;
	friend bool operator < (node x,node y){
		return x.val>y.val;
	}
}sa[N];
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;i++){
			v[i].clear();g[i].clear();f[i].clear();
			v[i].resize(m+3);
			g[i].resize(m+3);
			f[i].resize(m+3);
			for(int k=1;k<=m;k++){
				x=read();
				v[i][k]=x;
			}
			f[i][m+1]=1e9;
			for(int k=m;k>=1;k--){
				g[i][k]=max(g[i][k+1],v[i][k]);
				f[i][k]=min(f[i][k+1],v[i][k]);
			}
		}
		bool flag=0;
		for(int k=1;k<=n;k++)pb[k]=1e9,pa[k]=0;
		for(int i=1;i<m;i++){
			for(int k=1;k<=n;k++){
				pa[k]=max(pa[k],v[k][i]);
				pb[k]=min(pb[k],v[k][i]);
				sa[k]={pa[k],k};
			}
			sort(sa+1,sa+n+1);
			for(int k=0;k<=n+1;k++)ha[k]=0,hb[k]=1e9,tmp[k]=1e9;
			for(int k=1;k<=n;k++){
				ha[k]=max(ha[k-1],g[sa[k].id][i+1]);
			}
			for(int k=n;k>=1;k--){
				hb[k]=min(hb[k+1],f[sa[k].id][i+1]);
			}
			for(int k=1;k<=n;k++){
				tmp[k]=min(tmp[k-1],pb[sa[k].id]);
			}
			int ca=0;
			for(int k=1;k<n;k++){
				if(tmp[k]>sa[k+1].val && ha[k]<hb[k+1]){
					ca=k;flag=1;break;
				}
			}
			if(!flag)continue;
			puts("YES");
			for(int k=1;k<=n;k++){
				if(k<=ca)ans[sa[k].id]=1;
				else ans[sa[k].id]=2;
			}
			for(int k=1;k<=n;k++){
				if(ans[k]==1)cout<<"R";
				else cout<<"B";
			}
			cout<<" "<<i<<'\n';
			break;
		}
		if(!flag){
			puts("NO");
		}
	}
	return 0;
}
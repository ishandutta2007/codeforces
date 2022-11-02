#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#include<ctime>
#include<random>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
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
	mt19937 rnd(time(0)^(ll)(new char));
	int rend(int x){
		return rnd()%x+1;
	//	return rand()%x+1;
	}
	void rendom_shuffle(int *a,int len){
		shuffle(a+1,a+len+1,rnd);
	//	random_shuffle(a+1,a+len+1);
	}
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
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
const int N=2e4+5;
int T,n,a[N],/*b[N],st[N],*/bj[N],top;
/*int query(int x,int y,int z){
	return ((b[x]+b[y]+b[z]>=2)^1);
}*/
int ask(int x,int y,int z){
	cout<<"? "<<x<<" "<<y<<" "<<z<<endl;
	fflush(stdout);
	int tmp;cin>>tmp;
	//tmp=query(x,y,z);
	if(tmp==-1)while(1);
	return (tmp^1);
}
int main(){
	#ifdef newbiewzs
	//	freopen("data.in","r",stdin);
	#else
	#endif
//	srand(time(0)^(ll)(new char));
	cin>>T;
//	T=10;
	memset(a,-1,sizeof(a));
	while(T--){
		cin>>n;
		/*if(n==9999){
			puts("NEW CHAR");
			return 0;
		}*/
		int tx=0,ty=0;
		for(int i=1;i<=n;i+=3){
			int tmp=ask(i,i+1,i+2);
			bj[i]=tmp;
			if(tmp==0)tx=i;
			else ty=i;
		}
		
		int x=ty,y=ty+1; // x=1 y=0
		bool flag=0;
		int jl=0;
		for(int i=tx;i<=tx+1;i++){
			if(ask(x,y,i)==0){
				jl=i;flag=1;break;
			}
		}
		a[jl]=1;
		if(!flag){
			if(ask(tx,tx+1,x)==0)y=tx;
			else y=tx+2;
		}
		else{
			if(ask(ty+1,ty+2,jl)==1){
				swap(x,y);
			}
		}
		a[x]=1;a[y]=0;
		for(int i=1;i<=n;i+=3){
			if(x>=i && x<=i+2)continue;
			if(y>=i && y<=i+2)continue;
			if(bj[i]==0){
				if(ask(x,i,i+1)==0){
					a[i]=0;a[i+1]=0;
					if(ask(x,i+1,i+2)==0)a[i+2]=0;
					else a[i+2]=1;
				}
				else{
					a[i+2]=0;
					if(ask(x,i,i+2)==1)a[i]=1,a[i+1]=0;
					else a[i+1]=1,a[i]=0;
				}
			}
			else{
				if(ask(y,i,i+1)==0){
					a[i+2]=1;
					if(ask(y,i,i+2)==0)a[i]=0,a[i+1]=1;
					else a[i+1]=0,a[i]=1;
				}
				else{
					a[i]=a[i+1]=1;
					if(ask(y,i,i+2)==1)a[i+2]=1;
					else a[i+2]=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==-1){
				a[i]=ask(x,y,i);
			}
		}
		int tot=0;
		for(int i=1;i<=n;i++)if(a[i]==1)tot++;
		cout<<"! "<<tot<<" ";
		for(int i=1;i<=n;i++)if(a[i]==1)cout<<i<<" ";cout<<endl;
		fflush(stdout);
		for(int i=1;i<=n;i++)a[i]=-1;
		top=0;
	}
	return 0;
}
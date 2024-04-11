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
// #pragma GCC optimize(3)
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	mt19937 rnd(time(0)^(ll)(new char));
	int rend(int x){
		return rnd()%x+1;
	}
	void rendom_shuffle(int *a,int len){
		shuffle(a+1,a+len+1,rnd);
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
	char ssss[19999999],tttt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ssss[++ssl]='-',x=(-x);
		if(!x) ssss[++ssl]='0';for(ttl=0;x;x/=10) tttt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ssss[++ssl]=tttt[ttl];return ssss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ssss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
	/*	char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;*/
		int x;
		cin>>x;
		return x;
	}
}using namespace IO_BUFF;
/*namespace CFConTest{
	const int mod=998244353;
	inline int add(const int &x,const int &y){
		return (x+y>=mod?x+y-mod:x+y);
	}
	inline int del(const int &x,const int &y){
		return (x-y<0?x-y+mod:x-y);
	}
	int ksm(int x,int k){
		int base=1;
		while(k){
			if(k&1)base=1ll*base*x%mod;
			k>>=1;
			x=1ll*x*x%mod;
		}
		return base;
	}
};
using namespace CFConTest;*/
const int N=105;
int n,px,py,nx,ny,ax,ay,ox,oy,a[N],b[N],cx[N],cy[N],pre[N*N],vis[N],tap[N];
int v[N];
int gx(){
	int summ=0;
	for(int i=1;i<=n;i++){
		if(v[i]>2)summ=summ+(v[i]*(v[i]-1)*(v[i]-2)/6);
	}
	return summ;
}
int gy(){
	int summ=0;
	for(int i=1;i<=n-2;i++){
		summ=summ+v[i]*v[i+1]*v[i+2];
	}
	return summ;
}
void query(int x){
	px=nx;py=ny;b[x]++;
//	v[x]++;
	cout<<"+ "<<x<<endl;fflush(stdout);
	nx=read();ny=read();fflush(stdout);
//	nx=gx();ny=gy();
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
//	for(int i=1;i<=n;i++)tap[i]=v[i]=read();
	
	nx=cx[0]=read();ny=cy[0]=read();
//	nx=cx[0]=gx();ny=cy[0]=gy();
	for(int i=1;i<=n;i++)pre[i*(i-1)/2]=i;
	for(int i=1;i<n;i++){
		query(i);
		cx[i]=nx;cy[i]=ny;
	}
	if(cx[1]!=cx[0]){
		a[1]=pre[cx[1]-cx[0]];
	}
	ay=cy[1]-cy[0]; // a[2] * a[3]
	ox=cx[1];oy=cy[1];
	
	if(cx[2]!=cx[1])a[2]=pre[cx[2]-cx[1]],vis[2]=1;
	
	if(cx[3]!=cx[2])a[3]=pre[cx[3]-cx[2]],vis[3]=1;
	
	query(1);
	if(!a[1]){
		if(nx!=cx[n-1])a[1]=pre[nx-cx[n-1]]-1;
	}
	int tx=ny-cy[n-1]-ay-1; // a[2]+a[3]
	if(!tx)a[2]=a[3]=0;
	if(tx==1){
		if(cy[2]-oy>0)a[2]=0,a[3]=1;
		else a[3]=0,a[2]=1;
	}
	if(tx==2){
		if(vis[2])a[3]=2-a[2];
		else if(vis[3])a[2]=2-a[3];
		else a[2]=a[3]=1;
	}
	else {
		if(vis[2])a[3]=tx-a[2];
		else if(vis[3])a[2]=tx-a[3];
	}
	for(int i=4;i<n;i++){
		if(cx[i]!=cx[i-1]){
			a[i]=pre[cx[i]-cx[i-1]];
		}
		else {
			if((cy[i-1]-cy[i-2])-(a[i-3]+1)*(a[i-2]+1)>0)a[i]=1;
		}
	}
	a[n]=((cy[n-1]-cy[n-2])-(a[n-3]+1)*(a[n-2]+1))/(a[n-2]+1);
	cout<<"! ";
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
		/*if(a[i]!=tap[i]){
			cout<<"fck";return 0;
		}*/
	}
	cout<<endl;
	fflush(stdout);
	return 0;
}
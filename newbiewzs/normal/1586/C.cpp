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
const int N=1e6+5;
int T,n,m,h,s[N],ans[N];
vi a[N];
char c[N];
struct node{
	int l,r,id;
}q[N];
int bit[N];
void add(int x){
	for(;x<=m;x+=(x&(-x)))bit[x]++;
}
int query(int x){
	int summ=0;
	for(;x;x-=(x&(-x)))summ+=bit[x];
	return summ;
}
int query(int x,int y){
	if(x>y)return 0;
	return query(y)-query(x-1);
}
void solve(){
	n=read();m=read();
	a[0].resize(m+5);
	for(int i=1;i<=n;i++){
		scanf("%s",c+1);
		a[i].resize(m+5);
		for(int k=1;k<=m;k++){
			if(c[k]=='X')a[i][k]=0;
			else a[i][k]=1;
		}
	}
	for(int i=2;i<=m;i++){
		for(int k=2;k<=n;k++){
			if(!a[k-1][i] && !a[k][i-1])s[i]=1;
		}
		if(s[i])add(i);
	}
	h=read();
	for(int i=1;i<=h;i++){
		q[i].l=read();q[i].r=read();q[i].id=i;
		ans[i]=query(q[i].l+1,q[i].r);
		if(!ans[i])puts("YES");
		else puts("NO");
	}
}
int main(){
	#ifdef newbiewzs
	#else
	#endif
//	cin>>T;
	T=1;
	while(T--){
		solve();
	}
	return 0;
}
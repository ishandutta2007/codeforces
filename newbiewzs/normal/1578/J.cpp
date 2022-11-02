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
#define int long long
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
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
const int N=2e5+5;
int T;
int n,a,b,c,sa,sb,st[N],top;
char s[N];
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();a=read();b=read();c=read();sa=sb=top=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			if(s[i]==s[i+1]){
				if(s[i]=='0')sa++;
				if(s[i]=='1')sb++;
			}
		}
		int tmp=min(sa,sb);
		int ans=tmp*(a+b);
		int cnt=0;
		sa-=tmp;sb-=tmp;
		if(sa){
			ans+=a;sa--;
		}
		if(sb){
			ans+=b;sb--;
		}
		for(int i=1;i<=n;i++){
			if(s[i]=='1')continue;
			int head=i;
			while(head<n && s[head+1]=='0')head++;
			if(i!=1 && head!=n)st[++top]=head-i;
			else cnt++;
			i=head;
		}
		sort(st+1,st+top+1);
		int tot=0;
		for(int i=1;i<=top;i++){
			if(tmp>=st[i]){
				tmp-=st[i];
				tot++;
			}
		}
		if(b>c){
			ans=ans+(b-c)*tot;
			/*if(min(sb-tot+1,cnt)>0)*/ans=ans+(b-c)*min(sb/*-tot+1*/,cnt);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
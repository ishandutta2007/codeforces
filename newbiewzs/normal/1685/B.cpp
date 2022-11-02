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
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';
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
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
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
const int N=5e5+5;
int T,n;
int a,b,c,d;
char s[N];
int st[N],id[N],cd[N],summ,top;
int sa[N],bh[N],head;
vi ta,tb;
void solve(){
	int len=cd[head]-cd[1];
	if(sa[head]==1)len++;
	if(len%2==1){
		summ+=len/2;
		return ;
	}
	if(bh[1]==1)ta.pb(len);
	else tb.pb(len);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	int fl=0,cnt=0;
//	if(T==2665)fl=1;
	while(T--){
		cnt++;
		a=read();b=read();c=read();d=read();
		scanf("%s",s+1);n=strlen(s+1);
		if(fl==1 && cnt==127){
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<'\n';
			printf("%s\n",s+1);
		}
		int ca=0,cb=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='A')ca++;
			else cb++;
		}
		if(a+c+d!=ca || b+c+d!=cb){
			puts("NO");
		}
		else{
			top=summ=0;ta.clear();tb.clear();
			for(int i=1;i<=n;i++){
				if(s[i]!=s[i-1])st[++top]=1,id[top]=s[i]-'A'+1;
				else st[top]++;
			}
			for(int i=1;i<=top;i++){
				st[i]=min(st[i],2);
			}
			int pre=1;
			for(int i=1;i<=top;i++){
				if(st[i]==2 && st[i-1]==2){
					if(id[i]==1){
						d--;
					}
					else {
						c--;
					}
				}
			}
			for(int i=1;i<=top;i++){
				if(st[i]==2 && st[i-1]==2){
					pre=i;
				}
				else if(st[i]==2){
					head=0;
					for(int k=pre;k<=i;k++)sa[++head]=st[k],cd[head]=cd[head-1]+sa[head],bh[head]=id[k];
					solve();
					pre=i;
				}
				
			}
			head=0;
			for(int i=pre;i<=top;i++){
				sa[++head]=st[i];
				cd[head]=cd[head-1]+sa[head];
				bh[head]=id[i];
			}
			solve();
			sort(ta.begin(),ta.end());
			sort(tb.begin(),tb.end());
			for(int i=0;i<ta.size();i++){
				if(!ta[i])continue;
				if(c>=ta[i]/2)c-=ta[i]/2;
				else{
					summ+=ta[i]/2-1;
				}
			}
			for(int i=0;i<tb.size();i++){
				if(!tb[i])continue;
				if(d>=tb[i]/2)d-=tb[i]/2;
				else{
					summ+=tb[i]/2-1;
				}
			}
			if(!fl){
				if(max(c,0)+max(d,0)<=summ){
					puts("YES");
				}
				else puts("NO");	
			}
			
		//	cout<<'\n';
		}
	}
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}
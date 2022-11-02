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
const int N=105;
int n,m,k,st[N],top;
char a[N];
char b[N];
int ta[28],tb[28];
int ga(){
	for(int i=0;i<26;i++){
		if(ta[i]){
		//	ta[i]--;
			return i;
		}
	}
}
int gb(){
	for(int i=0;i<26;i++){
		if(tb[i]){
		//	ta[i]--;
			return i;
		}
	}
}
int pa(){
	for(int i=0;i<26;i++){
		if(ta[i]){
			return 1;
		}
	}
	return 0;
}
int pb(){
	for(int i=0;i<26;i++){
		if(tb[i]){
			return 1;
		}
	}
	return 0;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	int kel=read();
	for(int T=1;T<=kel;T++){
		n=read();m=read();k=read();
		scanf("%s",a+1);
		scanf("%s",b+1);
		for(int i=1;i<=n;i++)ta[a[i]-'a']++;
		for(int i=1;i<=m;i++)tb[b[i]-'a']++;
		int ca=0,cb=0,pre=0,cnt=0;
		while(pa() && pb()){
			if((pre==1 || (pre==0 && cnt<k)) && ga()<gb()){
				if(pre==0)cnt++;
				else pre=0,cnt=1;
				st[++top]=ga();
				ta[st[top]]--;
			}
			else if(pre==1 && cnt==k){
				st[++top]=ga();
				ta[st[top]]--;
				pre=0;cnt=1;
			}
			else {
				st[++top]=gb();
				tb[st[top]]--;
				if(pre==1)cnt++;
				else pre=1,cnt=1;
			}
		}
		for(int i=1;i<=top;i++){
			cout<<(char)(st[i]+'a');
		}
		cout<<'\n';
		top=0;
		mem0(ta);
		mem0(tb);
	}
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}
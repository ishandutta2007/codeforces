#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
//#ifdef mod
int mod;
int pow(int x,ll y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
//#endif
int fir[1010],dis[2010],nxt[2010],id,du[1010];
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int main(){
#ifdef LOCAL
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b;
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a),++du[a],++du[b];
	std::queue<int>que;
	for(int i=1;i<=n;++i)if(du[i]==1)que.push(i);
	while(que.size()>=2){
		int x=que.front();que.pop();
		int y=que.front();que.pop();
		printf("? %d %d\n",x,y);fflush(stdout);
		int r=gi();
		if(r==x||r==y)return printf("! %d\n",r),fflush(stdout),0;
		--du[x],--du[y];
		for(int i=fir[x];i;i=nxt[i])if(du[dis[i]]){x=dis[i];break;}
		for(int i=fir[y];i;i=nxt[i])if(du[dis[i]]){y=dis[i];break;}
		if(--du[x]==1)que.push(x);
		if(--du[y]==1)que.push(y);
	}
	printf("! %d\n",que.front());fflush(stdout);
	return 0;
}
#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
int fir[200010],dis[400010],nxt[400010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int p[200010];
int dist[200010],que[200010],hd,tl;
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<=m;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	int k=gi();
	for(int i=1;i<=k;++i)p[i]=gi();
	que[tl++]=p[k];dist[p[k]]=1;
	while(hd^tl){
		int x=que[hd++];
		for(int i=fir[x];i;i=nxt[i])
			if((~i&1)&&!dist[dis[i]])dist[dis[i]]=dist[x]+1,que[tl++]=dis[i];
	}
	int ans1=0,ans2=0;
	for(int i=1;i<k-1;++i){
		if(dist[p[i+1]]+1>dist[p[i]])++ans1,++ans2;
		else{
			bool flg=0;
			for(int j=fir[p[i]];j;j=nxt[j])
				if((j&1)&&dist[dis[j]]+1==dist[p[i]]&&dis[j]!=p[i+1])flg=1;
			ans2+=flg;
		}
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
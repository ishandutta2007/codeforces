#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[500010],dis[500010],nxt[500010],id;char w[500010];
void link(int a,int b,char c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
int QAQ[100],m;
struct uo_map{
	std::unordered_map<int,int>s;
	int tagk,tags;
	uo_map(){tagk=tags=0;}
	int size(){return s.size();}
	int get(int x){
		if(s.count(x^tagk))return s[x^tagk]+tags;
		return -1e9;
	}
	void set(int x,int o){
		if(s.count(x^tagk))s[x^tagk]=std::max(s[x^tagk],o-tags);
		else s[x^tagk]=o-tags;
	}
	void swap(uo_map&B){s.swap(B.s),std::swap(tagk,B.tagk),std::swap(tags,B.tags);}
}M[500010];
void Union(uo_map&A,uo_map&B,int&res,int o){
	/*
	printf("Union %d %d\n",res,o);
	puts("A:");for(auto[x,y]:A.s)printf("%d %d\n",x^A.tagk,y+A.tags);
	puts("B:");for(auto[x,y]:B.s)printf("%d %d\n",x^B.tagk,y+B.tags);
	puts("");*/
	if(A.size()>B.size()){
		for(auto[x,y]:B.s)
			for(int i=1;i<=m;++i)
				res=std::max(res,A.get(x^B.tagk^QAQ[i]^o)+y+B.tags+1);
		for(auto[x,y]:B.s)A.set(x^B.tagk^o,y+B.tags+1);
	}else{
		A.swap(B);A.tagk^=o;++A.tags;
		for(auto[x,y]:B.s)
			for(int i=1;i<=m;++i)
				res=std::max(res,A.get(x^B.tagk^QAQ[i])+y+B.tags);
		for(auto[x,y]:B.s)A.set(x^B.tagk,y+B.tags);
	}
}
int ans[500010];
void dfs(int x){
	M[x].set(0,0);
	for(int i=fir[x];i;i=nxt[i]){
		dfs(dis[i]),ans[x]=std::max(ans[x],ans[dis[i]]);
		Union(M[x],M[dis[i]],ans[x],1<<w[i]);
	}
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	QAQ[m=1]=0;for(int i=0;i<22;++i)QAQ[++m]=1<<i;
	int n=gi(),fa;char ch;
	for(int i=2;i<=n;++i)fa=gi(),ch=getchar(),link(fa,i,ch-'a');
	dfs(1);for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}
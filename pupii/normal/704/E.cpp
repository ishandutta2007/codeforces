#include<bits/stdc++.h>
#define il inline
#define vd void
#define eps 1e-10
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int fir[100010],dis[200010],nxt[200010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int siz[100010],son[100010],fa[100010],dep[100010],top[100010];
il vd dfs(int x){
	siz[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(fa[x]==dis[i])continue;
		fa[dis[i]]=x;
		dep[dis[i]]=dep[x]+1;
		dfs(dis[i]);
		siz[x]+=siz[dis[i]];
		if(siz[son[x]]<siz[dis[i]])son[x]=dis[i];
	}
}
il vd dfs(int x,int tp){
	top[x]=tp;if(son[x])dfs(son[x],tp);
	for(int i=fir[x];i;i=nxt[i])if(fa[x]!=dis[i]&&son[x]!=dis[i])dfs(dis[i],dis[i]);
}
il int LCA(int a,int b){
	while(top[a]!=top[b])
		if(dep[top[a]]>dep[top[b]])a=fa[top[a]];
		else b=fa[top[b]];
	return dep[a]<dep[b]?a:b;
}
struct naive{int st,ed,v;double t;};
double nowt;
il bool operator<(const naive&a,const naive&b){
	double pa=a.st+a.v*(nowt-a.t),pb=b.st+b.v*(nowt-b.t);
	if(fabs(pa-pb)>eps)return pa<pb;
	return a.t<b.t;
}
il bool cmp_t(const naive&a,const naive&b){return a.t<b.t;}
il bool cmp_edt(const naive&a,const naive&b){return a.t+(a.v?fabs((a.st-a.ed)*1.0/a.v):0)<b.t+(b.v?fabs((b.st-b.ed)*1.0/b.v):0);}
il double calc(const naive&a,const naive&b){
	if(a.st==b.st&&fabs(a.t-b.t)<eps)return a.t;
	if(!a.v||!b.v){
		if(a.v){
			if(b.t>a.t&&a.t+1.0*(b.st-a.st)/a.v==b.t)return b.t;
		}else if(b.v){
			if(a.t>b.t&&b.t+1.0*(a.st-b.st)/b.v==a.t)return a.t;
		}
		return 1e9;
	}
	if(a.v==b.v){
		if(a.v&&fabs(1.0*(a.st-b.st)/a.v-b.t+a.t)>eps){
			if(a.t<b.t&&fabs((b.t-a.t)*a.v+a.st-b.st)<eps)return b.t;
			if(b.t<=a.t&&fabs((a.t-b.t)*b.v+b.st-a.st)<eps)return a.t;
		}
		return 1e9;
	}
	double ct,cx;
	ct=(b.st-a.st-a.v*(b.t-a.t))/(a.v-b.v),cx=ct*b.v+b.st;
	if(fabs(a.st-cx)>eps&&fabs(a.ed-cx)>eps&&(a.st-cx)*(a.ed-cx)>0)return 1e9;
	if(fabs(b.st-cx)>eps&&fabs(b.ed-cx)>eps&&(b.st-cx)*(b.ed-cx)>0)return 1e9;
	return ct+b.t;
}
std::vector<naive>S[100010];
std::multiset<naive>st;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	dep[1]=1;dfs(1),dfs(1,1);
	int v,lca;double t;
	for(int i=1;i<=m;++i){
		t=gi(),v=gi(),a=gi(),b=gi();
		if(a==b){S[top[a]].push_back((naive){dep[a],dep[a],0,t});continue;}
		lca=LCA(a,b);
		bool flg=1;
		while(top[a]!=top[lca]){
			S[top[a]].push_back((naive){dep[a],dep[top[a]]-1,-v,t});
			t+=1.0*(dep[a]-dep[top[a]]+1)/v;
			a=fa[top[a]];
		}
		if(a!=lca){
			S[top[a]].push_back((naive){dep[a],dep[lca],-v,t});
			if(top[a]==top[lca])flg=0;
		}
		t+=1.0*(dep[a]-dep[lca])/v;
		t+=1.0*(dep[b]-dep[lca])/v;
		while(top[b]!=top[lca]){
			t-=1.0*(dep[b]-dep[top[b]]+1)/v;
			S[top[b]].push_back((naive){dep[top[b]]-1,dep[b],v,t});
			b=fa[top[b]];
		}
		t-=1.0*(dep[b]-dep[lca])/v;
		if(b!=lca){
			S[top[b]].push_back((naive){dep[lca],dep[b],v,t});
			if(top[b]==top[lca])flg=0;
		}
		if(flg)S[top[lca]].push_back((naive){dep[lca],dep[lca],0,t});
	}
	double ans=1e9;
	std::multiset<naive>::iterator pre,nxt;
	std::vector<naive>A,B;
	for(int x=1;x<=n;++x){
		A=B=S[x];
		std::sort(A.begin(),A.end(),cmp_t);
		std::sort(B.begin(),B.end(),cmp_edt);
		st.clear();
		double res=1e9;
		for(int i=0,p=0;i<A.size();++i){
			while(p<B.size()&&B[p].t+(B[p].v?fabs((B[p].st-B[p].ed)*1.0/B[p].v):0)+eps<A[i].t){
				st.erase(st.find(B[p]));
				nxt=st.lower_bound(B[p]);
				if(nxt!=st.end()&&nxt!=st.begin())pre=nxt,--pre,res=std::min(res,calc(*pre,*nxt));
				++p;
			}
			nowt=A[i].t;if(nowt+eps>res)goto ed;
			nxt=st.lower_bound(A[i]);
			if(nxt!=st.end())res=std::min(res,calc(A[i],*nxt));
			if(nxt!=st.begin())--nxt,res=std::min(res,calc(A[i],*nxt));
			st.insert(A[i]);
		}
	  ed:ans=std::min(ans,res);
	}
	if(ans==1e9)puts("-1");
	else printf("%.10lf\n",ans);
	return 0;
}
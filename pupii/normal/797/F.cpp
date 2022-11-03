#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct hole{int p,c;}h[1000010];
int px[1000010],py[2000010],stk[1000010],tp;
struct magic{
	ll stk[2000010],tag,tp;
	void push(ll x){stk[++tp]=x-tag;}
	ll top(){return assert(tp),tag+stk[tp];}
	void pop(){assert(tp),--tp;}
	void Add(ll x){tag+=x;}
	bool empty(){return!tp;}
}sn,sp;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();ll sc=0;
	for(int i=1;i<=n;++i)px[i]=gi();
	std::sort(px+1,px+n+1);
	for(int i=1;i<=m;++i)h[i].p=gi(),sc+=h[i].c=gi();
	std::sort(h+1,h+m+1,[](hole a,hole b){return a.p<b.p;});
	int _m=0;
	for(int i=1,p=1;i<=n;++i){
		while(p<=m&&h[p].p<=px[i]){stk[++tp]=p++;if(!h[stk[tp]].c)--tp;}
		if(tp){
			py[++_m]=h[stk[tp]].p;
			if(!--h[stk[tp]].c)--tp;
		}
	}
	tp=0;
	for(int i=n,p=m;i;--i){
		while(p&&h[p].p>=px[i]){stk[++tp]=p--;if(!h[stk[tp]].c)--tp;}
		if(tp){
			py[++_m]=h[stk[tp]].p;
			if(!--h[stk[tp]].c)--tp;
		}
	}
	m=_m;std::sort(py+1,py+m+1);
	if(sc<n)return puts("-1"),0;
	int p1=1,p2=1;
	sp.push(0);
	while(p1<=n||p2<=m)
		if(p1<=n&&(p2>m||px[p1]<=py[p2])){
			if(sp.empty())sp.push(1e18);
			sn.push(sp.top());sp.pop();
			sn.Add(-px[p1]);sp.Add(px[p1]);
			++p1;
		}else{
			if(sn.empty())sn.push(1e18);
			ll _=sp.empty()?1e18:sp.top();
			sn.Add(py[p2]);sp.Add(-py[p2]);
			sp.push(std::min(sn.top(),_));sn.pop();
			++p2;
		}
	printf("%lld\n",sp.top());
	return 0;
}
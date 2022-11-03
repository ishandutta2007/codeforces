#include<bits/stdc++.h>
#define B 316
#define maxn 100010
#define pr std::pair<ll,int>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct line{ll k,b;ll get(int x){return x*k+b;}};
int a[maxn],bl[B+10],br[B+10],bel[maxn],m;
int tm[maxn],del[maxn];ll addb[maxn];
double crsx(const line&a,const line&b){return 1.0*(b.b-a.b)/(a.k-b.k);}
struct Convex{
	int hd,tl,id[B+10],s[B+10],len,tagk;ll tagb;
	line que[B+10];
	void build(int b,bool o=0){
		if(o){
			for(int i=bl[b];i<=br[b];++i)s[++len]=i;
			std::sort(s+1,s+len+1,[&](int x,int y){return a[x]<a[y];});
		}
		hd=tl=0;
		for(int _=1,i;_<=len;++_)
			if(!del[i=s[_]]){
				tm[i]+=tagk;addb[i]+=tagb;
				line now={a[i],1ll*tm[i]*a[i]+addb[i]};
				if((hd^tl)&&que[tl-1].k==a[i]){
					if(now.b>que[tl-1].b)--tl;
					else continue;
				}
				while((tl-hd>1)&&crsx(que[tl-1],now)<crsx(que[tl-1],que[tl-2]))--tl;
				id[tl]=i;que[tl++]=now;
			}
		tagk=tagb=0;
	}
	pr query(){
		if(hd==tl)return{-1e18,0};
		while((tl-hd>1)&&que[hd].get(tagk)<que[hd+1].get(tagk))++hd;
		return{que[hd].get(tagk)+tagb,id[hd]};
	}
}Conv[maxn/B+10];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)a[i]=gi(),bel[i]=(i-1)/B+1;
	m=bel[n];
	for(int i=1;i<=m;++i)bl[i]=(i-1)*B+1,br[i]=i*B;
	br[m]=n;
	for(int i=1;i<=n;++i)tm[i]=1;
	for(int i=1;i<=m;++i)Conv[i].build(i,1);
	ll ans=0,res=0;
	for(int i=1;i<=n;++i){
		pr P={-1e18,0};
		for(int j=1;j<=m;++j)P=std::max(P,Conv[j].query());
		res+=P.first;ans=std::max(ans,res);
		int p=P.second;
		del[p]=1;
		for(int j=1;j<bel[p];++j)Conv[j].tagb+=a[p];
		for(int j=bel[p]+1;j<=m;++j)++Conv[j].tagk;
		for(int j=bl[bel[p]];j<p;++j)addb[j]+=a[p];
		for(int j=p+1;j<=br[bel[p]];++j)++tm[j];
		Conv[bel[p]].build(bel[p]);
	}
	printf("%lld\n",ans);
	return 0;
}
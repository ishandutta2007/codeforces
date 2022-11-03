#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct op{int i,j,d;};
std::vector<op>ans;
struct stone{int s,i;}s[300010];
int t[300010];
std::vector<std::pair<int,int>>ol;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	ll sum=0;
	for(int i=1;i<=n;++i)s[i].s=gi(),s[i].i=i,sum-=s[i].s;
	for(int i=1;i<=n;++i)t[i]=gi(),sum+=s[i].s;
	if(sum)return puts("NO"),0;
	std::sort(s+1,s+n+1,[](const stone&a,const stone&b){return a.s<b.s;});std::sort(t+1,t+n+1);
	for(int i=1;i<=n;++i){
		int d=s[i].s-t[i];
		if(d<0)ol.push_back({s[i].i,-d});
		else if(d>0){
			while(d){
				if(ol.empty())return puts("NO"),0;
				int p=std::min(d,ol.back().second);
				ans.push_back({ol.back().first,s[i].i,p});
				d-=p;
				if((ol.back().second-=p)==0)ol.erase(ol.end()-1);
			}
		}
	}
	if(!ol.empty())return puts("NO"),0;
	puts("YES");
	printf("%d\n",ans.size());
	for(auto i:ans)printf("%d %d %d\n",i.i,i.j,i.d);
	return 0;
}
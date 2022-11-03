#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
std::vector<pr>ans;
int a[15010],cc=15555;
std::map<pr,int>M;
void fuck(pr s){
	int x=s.fi,y=s.se;
	if(!M.count({a[x],a[y]}))M[{a[x],a[y]}]=++cc;
	a[x]=a[y]=M[{a[x],a[y]}];
	ans.push_back({x,y});
}
void merge(std::vector<int>v1,std::vector<int>v2){
	assert(v1.size()==v2.size());
	for(int i=0;i<v1.size();++i)fuck({v1[i],v2[i]});
}
void work(int l,int r){
	if(l==r)return;
	int mid=l+r>>1;
	work(l,mid),work(mid+1,r);
	std::vector<int>v1,v2;
	for(int i=l;i<=mid;++i)v1.push_back(i);
	for(int i=mid+1;i<=r;++i)v2.push_back(i);
	merge(v1,v2);
}
struct qwq{int x;std::vector<int>p;};
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();
	int x=n;
	std::vector<qwq>s;
	for(int i=1;i<=n;++i)a[i]=i;
	while(x){
		int r=x,l=r-(x&-x)+1;
		work(l,r);
		std::vector<int>P;for(int i=l;i<=r;++i)P.push_back(i);
		s.push_back({r-l+1,P});
		x=l-1;
	}
	while(s.size()>2){
		if(s[0].x==s[1].x){
			merge(s[0].p,s[1].p);
			for(int i:s[1].p)s[0].p.push_back(i);
			s[0].x*=2;s.erase(s.begin()+1);
		}else{
			std::vector<int>P=s.back().p,P1,P2;
			for(int i=0;i<s[0].x;++i)P1.push_back(P[i]);
			for(int i=s[0].x;i<P.size();++i)P2.push_back(P[i]);
			merge(s[0].p,P1);
			for(int i:P1)s[0].p.push_back(i);
			s.back().p=P2;
			s.back().x-=s[0].x;
			s[0].x*=2;
		}
	}
	printf("%d\n",ans.size());
	for(pr s:ans)printf("%d %d\n",s.fi,s.se);
	return 0;
}
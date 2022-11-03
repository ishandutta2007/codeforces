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
pr A[2010],B[2010],C[2010];
struct qwq{int a,b,c;};
std::vector<qwq>v;
std::multiset<int>st;
int now[2010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<=n;++i)A[i].fi=gi(),A[i].se=gi();
	for(int i=1;i<=m;++i)B[i].fi=gi(),B[i].se=gi();
	B[++m]={-1e9,1000001};
	B[++m]={1000001,-1e9};
	std::sort(B+1,B+m+1);
	int _m=0;
	for(int i=m,Y=-2e9;i;--i)if(B[i].se>Y)C[++_m]=B[i],Y=B[i].se;
	m=_m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)
			v.push_back({std::max(0,C[j].se-A[i].se+1),i,std::max(0,C[j+1].fi-A[i].fi+1)});
	std::sort(all(v),[](qwq a,qwq b){return a.a==b.a?a.c>b.c:a.a<b.a;});
	int ans=1e9,lst=-1;
	memset(now,-1,sizeof now);
	for(qwq s:v){
		if(lst!=s.a&&st.size()==n)cnk(ans,lst+*st.rbegin());
		if(now[s.b]!=-1)st.erase(st.find(now[s.b]));
		st.insert(now[s.b]=s.c);
		lst=s.a;
	}
	cnk(ans,lst+*st.rbegin());
	printf("%d\n",ans);
	return 0;
}
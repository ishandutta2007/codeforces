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
int p[510];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();
	std::vector<pr>ans;
	int R=0;ans.push_back({0,-1});
	for(int i=1;i+1<=n;i+=2){
		ans.push_back({0,R});
		ans.push_back({0,R+1});
		ans.push_back({-1,R});
		ans.push_back({-1,R+1});
		ans.push_back({1,R});
		ans.push_back({1,R+1});
		ans.push_back({0,R+2});
		R+=3;
	}
	ans.push_back({0,-2});
	ans.push_back({1,-2});
	ans.push_back({2,-2});
	ans.push_back({3,-2});
	for(int i=-1;i<=R;++i)ans.push_back({3,i});
	if(n&1){
		ans.push_back({-1,R});
		ans.push_back({1,R});
		ans.push_back({-1,R+1});
		ans.push_back({0,R+1});
	}
	ans.push_back({0,R});
	ans.push_back({1,R});
	ans.push_back({2,R});
	std::sort(all(ans));
	ans.erase(std::unique(all(ans)),ans.end());
	printf("%d\n",ans.size());
	for(pr s:ans)printf("%d %d\n",s.fi,s.se);
	return 0;
}
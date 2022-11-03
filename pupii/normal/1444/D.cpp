#include<bits/stdc++.h>
typedef long long ll;
#define mod 998244353
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
int n,A[1010],B[1010];
std::bitset<501*1001>bit[501];
bool get(int*A,std::vector<int>&p,std::vector<int>&q){
	for(int i=1;i<=n;++i)bit[i]=0;
	int sum=0;
	for(int i=1;i<=n;++i)bit[i]=bit[i-1]|(bit[i-1]<<A[i]),sum+=A[i];
	if((sum&1)||!bit[n][sum>>1])return 0;
	int i=n,j=sum>>1;
	while(i){
		if(bit[i-1][j])p.push_back(A[i]);
		else assert(bit[i-1][j-A[i]]),j-=A[i],q.push_back(A[i]);
		--i;
	}
	return 1;
}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	bit[0][0]=1;
	int qwq=gi();
	while(qwq--){
		int n=gi();for(int i=1;i<=n;++i)A[i]=gi();
		int m=gi();for(int i=1;i<=m;++i)B[i]=gi();
		::n=n;
		if(n!=m){puts("No");continue;}
		std::vector<int>Al,Ar,Bu,Bd;
		if(!get(A,Al,Ar)||!get(B,Bu,Bd)){puts("No");continue;}
		puts("Yes");
		std::vector<int>AA,BB;
		if(Al.size()<Ar.size())std::swap(Al,Ar);
		if(Bu.size()>Bd.size())std::swap(Bu,Bd);
		std::sort(all(Al),std::greater<int>());
		std::sort(all(Ar),std::greater<int>());
		std::sort(all(Bu));
		std::sort(all(Bd));
		for(int i:Ar)AA.push_back(i);
		for(int i:Al)AA.push_back(-i);
		for(int i:Bd)BB.push_back(i);
		for(int i:Bu)BB.push_back(-i);
		int x=0,y=0;
		for(int i=0;i<n;++i){
			x+=AA[i];
			printf("%d %d\n",x,y);
			y+=BB[i];
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}
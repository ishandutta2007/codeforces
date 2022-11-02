#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#define pb emplace_back
#define mp std::make_pair
#define fi first
#define se second
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,int>pli;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vll;
typedef vector<pii>vpii;
template<typename T>T cmax(T &x, T y){return x=x>y?x:y;}
template<typename T>T cmin(T &x, T y){return x=x<y?x:y;}
template<typename T>
T &read(T &r){
	r=0;bool w=0;char ch=getchar();
	while(ch<'0'||ch>'9')w=ch=='-'?1:0,ch=getchar();
	while(ch>='0'&&ch<='9')r=r*10+(ch^48),ch=getchar();
	return r=w?-r:r;
}
template<typename T1,typename... T2>
void read(T1 &x, T2& ...y){ read(x); read(y...); }
#define flh fflush(stdout)
int Scan(int x,int y){
	printf("SCAN %d %d\n",x,y);
	flh;
	int t;read(t);
	return t;
}
int Dig(int x,int y){
	printf("DIG %d %d\n",x,y);
	flh;
	int t;read(t);
	return t;
}
void solve(){
	int n,m;read(n,m); 
	int abcd=Scan(1,1)+4;
	int _a_cbd=Scan(n,1)-n-n+2;
	int bd=(abcd+_a_cbd)/2;
	int ac=abcd-bd;
	//
	int a=0,b=0,c=0,d=0;
	//
	int qwq=Scan(ac/2,1);
	for(int i=1;i<=ac;i++)
		if(abs(i-ac/2)+abs(ac-i-ac/2)+bd-2==qwq)
			a=i,c=ac-i;
	//
	int qaq=Scan(1,bd/2);
	for(int i=1;i<=bd;i++)
		if(abs(i-bd/2)+abs(bd-i-bd/2)+ac-2==qaq)
			b=i,d=bd-i;
	if(Dig(a,b)){
		Dig(c,d);
	}
	else{
		Dig(a,d);
		Dig(c,b);
	}
}
signed main(){
	int T;read(T);while(T--)solve();
	return 0;
}
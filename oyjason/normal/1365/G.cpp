#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define LL long long
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define pli pair<LL,int>
#define mp make_pair
#define pb push_back
using namespace std;
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 1000000007
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 320000
int n,m,p[M],ct[M],t[M];
LL w,ans[M];
inline void solve(int h){
	m=0;
	for(int i=1;i<=n;i++) if((p[i]>>h)&1) t[++m]=i;
	if(m==n||!m) return; cout<<"? "<<m;
	for(int i=1;i<=m;i++) cout<<" "<<t[i]; cout el;
	cin>>w;
	for(int i=1;i<=n;i++) if(!((p[i]>>h)&1)) ans[i]|=w;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	srand(time(0));
	cin>>n;
	int maxn=(1<<13),cnt=0;
	for(int i=0;i<maxn;i++) ct[i]=ct[i>>1]+(i&1);
	for(int i=0;i<maxn;i++) if(ct[i]==6) p[++cnt]=i;
	for(int i=0;i<13;i++) solve(i);
	cout<<"!";
	for(int i=1;i<=n;i++) cout<<" "<<ans[i]; cout el;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e6+5;
int n,m,q;
set<int> s[2][maxn];
const ll mod=998244353;
ll pw[maxn];
int t1[2][maxn],t2[2][maxn],c1=0,c2=0,t3[2],e1=0,e2=0;
void insert(int x,int y,bool t){
	s[t][x].insert(y);
	bool d=(x+y+t)%2;
	if(!t1[d][x]){
		if(t1[!d][x]) e1++;
		else c1++;
	}
	t1[d][x]++;
	if(!t2[d][y]){
		if(t2[!d][y]) e2++;
		else c2++;
	}
	t2[d][y]++;
	t3[d]++;
}
void erase(int x,int y){
	bool t=s[1][x].count(y),d=(x+y+t)%2;
	s[t][x].erase(y);
	t1[d][x]--;
	if(!t1[d][x]){
		if(t1[!d][x]) e1--;
		else c1--;
	}
	t2[d][y]--;
	if(!t2[d][y]){
		if(t2[!d][y]) e2--;
		else c2--;
	}
	t3[d]--;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	q=readint();
	pw[0]=1;
	for(int i=1;i<=max(n,m);i++) pw[i]=pw[i-1]*2%mod;
	while(q--){
		int x,y,t;
		x=readint();
		y=readint();
		t=readint();
		if(s[0][x].count(y)||s[1][x].count(y)) erase(x,y);
		if(t>=0) insert(x,y,t);
		ll ans=0;
		if(!e1) ans=(ans+pw[n-c1])%mod;
		if(!e2) ans=(ans+pw[m-c2])%mod;
		if(!t3[0]||!t3[1]) ans=(ans-1+mod)%mod;
		if(!t3[0]&&!t3[1]) ans=(ans-1+mod)%mod;
		printf("%lld\n",ans);
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
mt19937_64 rnd(time(0));
char s[500005],c[200005],z[700005];
int val,p10[500005],len;
int n,m,mod,l[700005],num[500005];
bool ss(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			RE 0;
		}
	}
	RE 1;
}
int get(int l,int r){
	RE (((num[r]-num[l-1]*p10[r-l+1])%mod+mod)%mod);
}
void check(int p1,int p2,int p3){
	if(p1<1||p2>n||p1>p2||p2>=p3)RE;
	int tval=(get(p1,p2)+get(p2+1,p3))%mod;
	if(tval==val){
		cout<<p1<<' '<<p2<<'\n'<<p2+1<<' '<<p3<<'\n';exit(0);
	}
}
signed main(){
	mod=1e8+rnd()%(int)9e8;
	while(!ss(mod)){
		mod=1e8+rnd()%(int)9e8;
	}
	scanf("%s%s",s+1,c+1);
	n=strlen(s+1);
	FOR(i,1,n){
		num[i]=(num[i-1]*10+(s[i]-'0'))%mod;
	}
	m=strlen(c+1);
	p10[0]=1;
	FOR(i,1,500000)p10[i]=p10[i-1]*10%mod;
	FOR(i,1,m){
		val=(val*10+c[i]-'0')%mod;
	}
	len=n+m;
	FOR(i,1,m){
		z[i]=c[i];
	}
	FOR(i,1,n)z[i+m]=s[i];
	int it=0;
	FOR(i,2,len){
		if(it+l[it]-1>=i){
			l[i]=l[i-it+1];
			gmin(l[i],it+l[it]-i);
		}
		while(i+l[i]<=len&&z[l[i]+1]==z[i+l[i]])l[i]++;
		if(i+l[i]>=it+l[it])it=i;
	}
	FOR(i,m-1,n-m+1)check(i-m+2,i,i+m-1);
	FOR(i,1,n){
		int len=l[i+m],t=m-len;
		check(i-t,i-1,i+m-1);
		check(i-t+1,i-1,i+m-1);
		check(i,i+m-1,i+m+t-1);
		check(i,i+m-1,i+m+t-2);
	} 
	RE 0;
}
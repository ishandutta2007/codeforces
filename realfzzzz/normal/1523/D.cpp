#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
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
typedef long long ll;
inline ll read2(){
	ll x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		x=x<<1|(c-'0');
		c=getchar();
	}
	return x;
}
mt19937 rnd(time(0)^20060122);
const int maxn=2e5+5,maxp=15;
int n,m,p;
ll a[maxn];
void FWT(int* f,int n){
	for(int i=1;i<n;i*=2)
		for(int j=0;j<n;j+=i*2)
			for(int k=j;k<j+i;k++) f[k+i]+=f[k];
}
int c,b[maxp+5],cnt[(1<<maxp)+5],f[(1<<maxp)+5];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	p=readint();
	for(int i=1;i<=n;i++) a[i]=read2();
	for(int i=1;i<(1<<p);i++) cnt[i]=cnt[i>>1]+(i&1);
	ll s=0;
	int ans=0;
	for(int i=0;i<50;i++){
		int x=rnd()%n+1;
		c=0;
		for(int j=0;j<m;j++) if(a[x]>>j&1) b[c++]=j;
		memset(f,0,sizeof(f));
		for(int j=1;j<=n;j++){
			int res=0;
			for(int k=0;k<c;k++) res|=(a[j]>>b[k]&1)<<k;
			f[((1<<c)-1)^res]++;
		}
		FWT(f,1<<c);
		for(int j=0;j<(1<<c);j++)
			if(f[((1<<c)-1)^j]>=(n+1)/2&&cnt[j]>ans){
				ll res=0;
				for(int k=0;k<c;k++) res|=(ll)(j>>k&1)<<b[k];
				s=res;
				ans=cnt[j];
			}
	}
	for(int i=m-1;i>=0;i--) printf("%lld",s>>i&1);
	return 0;
}
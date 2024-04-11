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
const int maxn=3e5+5;
int n,q,k,a[maxn];
struct stt{
	int n;
	vector<int> a,st[20],lg;
	void build(){
		st[0].resize(n+1);
		for(int i=1;i<=n;i++) st[0][i]=i;
		for(int i=1;(1<<i)<=n;i++){
			st[i].resize(n-(1<<i)+2);
			for(int j=1;j+(1<<i)-1<=n;j++)
				if(a[st[i-1][j]]<a[st[i-1][j+(1<<(i-1))]]) st[i][j]=st[i-1][j];
				else st[i][j]=st[i-1][j+(1<<(i-1))];
		}
		lg.resize(n+1);
		for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	}
	int query(int l,int r){
		int k=lg[r-l+1];
		if(a[st[k][l]]<a[st[k][r-(1<<k)+1]]) return st[k][l];
		else return st[k][r-(1<<k)+1];
	}
}st[maxn];
int b[maxn],s[maxn],tp;
vector<int> nxt[maxn];
vector<ll> f[maxn];
ll query(int x,int l,int r){
	if(l>r) return 0;
	int p=st[x].query(l,r);
	return f[x][l]-f[x][p]+1ll*st[x].a[p]*(r-p+1);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	q=readint();
	k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	stt st1;
	st1.n=n;
	st1.a.resize(n+1);
	for(int i=1;i<=n;i++) st1.a[i]=a[i];
	st1.build();
	for(int i=k+1;i<=n;i++) b[i]=a[st1.query(i-k,i)];
	for(int i=1;i<=k;i++){
		int m=(n-i)/k;
		st[i].n=m;
		st[i].a.resize(m+1);
		for(int j=1;j<=m;j++) st[i].a[j]=b[j*k+i];
		st[i].build();
		tp=0;
		nxt[i].resize(m+1);
		f[i].resize(m+2);
		for(int j=m;j>0;j--){
			while(tp&&b[j*k+i]<b[s[tp-1]*k+i]) tp--;
			nxt[i][j]=tp?s[tp-1]:m+1;
			f[i][j]=f[i][nxt[i][j]]+1ll*b[j*k+i]*(nxt[i][j]-j);
			s[tp++]=j;
		}
	}
	while(q--){
		int l,r;
		l=readint();
		r=readint();
		int x=l%k==0?k:l%k;
		printf("%lld\n",a[l]+query(x,(l-x)/k+1,(r-x)/k));
	}
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}
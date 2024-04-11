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
const int maxn=2e5+5;
int n,m,x,a[maxn],b[maxn],s[maxn],tp=1,mx[maxn];
int prea[maxn],suca[maxn],preb[maxn],sucb[maxn];
inline int lowbit(int x){
	return x&-x;
}
int c[maxn];
void modify(int x,int k){
	while(x<maxn){
		c[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x){
	int s=0;
	while(x){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
vector<int> qa[maxn],qb[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	x=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) b[i]=readint();
	mx[0]=maxn-1;
	for(int i=1;i<=n;i++){
		while(a[i]<a[s[tp-1]]){
			mx[tp-2]=max(mx[tp-2],mx[tp-1]);
			tp--;
		}
		prea[i]=max(mx[tp-1],a[i]);
		s[tp]=i;
		mx[tp++]=a[i];
	}
	tp=1;
	for(int i=1;i<=m;i++){
		while(b[i]<b[s[tp-1]]){
			mx[tp-2]=max(mx[tp-2],mx[tp-1]);
			tp--;
		}
		preb[i]=max(mx[tp-1],b[i]);
		s[tp]=i;
		mx[tp++]=b[i];
	}
	s[0]=n+1;
	tp=1;
	for(int i=n;i>0;i--){
		while(a[i]<=a[s[tp-1]]){
			mx[tp-2]=max(mx[tp-2],mx[tp-1]);
			tp--;
		}
		suca[i]=max(mx[tp-1],a[i]);
		s[tp]=i;
		mx[tp++]=a[i];
	}
	s[0]=m+1;
	tp=1;
	for(int i=m;i>0;i--){
		while(b[i]<=b[s[tp-1]]){
			mx[tp-2]=max(mx[tp-2],mx[tp-1]);
			tp--;
		}
		sucb[i]=max(mx[tp-1],b[i]);
		s[tp]=i;
		mx[tp++]=b[i];
	}
	for(int i=1;i<=n;i++) if(a[i]<=x) qa[x-a[i]].push_back(i);
	for(int i=1;i<=m;i++) qb[min(preb[i],sucb[i])].push_back(i);
	long long ans=0;
	for(int i=maxn-1;i>0;i--){
		for(int j:qa[i])
			ans+=query(x-a[j])-query(max(x-min(prea[j],suca[j]),0));
		for(int j:qb[i]) modify(b[j],1);
	}
	printf("%lld\n",ans);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}
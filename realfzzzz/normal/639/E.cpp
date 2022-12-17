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
const int maxn=1.5e5+5;
int n,p[maxn],t[maxn],ord[maxn];
ll t1[maxn],t2[maxn];
typedef long double ld;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) p[i]=readint();
	for(int i=1;i<=n;i++) t[i]=readint();
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,[](int a,int b){
		return 1ll*p[a]*t[b]>1ll*p[b]*t[a];
	});
	ll T=0;
	for(int i=1;i<=n;){
		int r=i;
		while(r<n&&1ll*p[ord[i]]*t[ord[r+1]]==1ll*p[ord[r+1]]*t[ord[i]]) r++;
		for(int j=i;j<=r;j++) t1[ord[j]]=T+t[ord[j]];
		for(int j=i;j<=r;j++) T+=t[ord[j]];
		for(int j=i;j<=r;j++) t2[ord[j]]=T;
		i=r+1;
	}
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,[](int a,int b){
		return p[a]<p[b];
	});
	ld l=0,r=1;
	while(r-l>1e-7){
		ld mid=l+(r-l)/2,mx=0;
		bool flag=1;
		for(int i=1;i<=n;){
			int r=i;
			while(r<n&&p[ord[i]]==p[ord[r+1]]) r++;
			for(int j=i;j<=r;j++) if(mx>p[ord[j]]*(1-mid*t2[ord[j]]/T)) flag=0;
			for(int j=i;j<=r;j++) mx=max(mx,p[ord[j]]*(1-mid*t1[ord[j]]/T));
			i=r+1;
		}
		if(flag) l=mid;
		else r=mid;
	}
	printf("%.11Lf\n",r);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}
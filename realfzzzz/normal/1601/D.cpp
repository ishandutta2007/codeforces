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
const int maxn=5e5+5;
int n,d,s[maxn],a[maxn],ord[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	d=readint();
	for(int i=1;i<=n;i++){
		s[i]=readint();
		a[i]=readint();
	}
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,[](int x,int y){
		if(max(s[x],a[x])!=max(s[y],a[y]))
			return max(s[x],a[x])<max(s[y],a[y]);
		return s[x]<s[y];
	});
	int cnt=0;
	for(int i=1;i<=n;i++) if(s[ord[i]]>=d){
		cnt++;
		d=max(d,a[ord[i]]);
	}
	printf("%d\n",cnt);
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}
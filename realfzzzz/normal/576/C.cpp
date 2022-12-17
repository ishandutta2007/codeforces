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
int n,x[maxn],y[maxn],ord[maxn];
void solve(int l,int r,bool d){
	if(l==r) return;
	int mid=l+(r-l)/2;
	nth_element(ord+l,ord+mid,ord+r+1,[d](int a,int b){
		return d?x[a]<x[b]:y[a]<y[b];
	});
	solve(l,mid,!d);
	solve(mid+1,r,!d);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++){
		x[i]=readint();
		y[i]=readint();
	}
	for(int i=1;i<=n;i++) ord[i]=i;
	solve(1,n,1);
	for(int i=1;i<=n;i++) printf("%d ",ord[i]);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}
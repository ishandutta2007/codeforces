#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,m,a[maxn],lg[maxn],mn[20][maxn],mx[20][maxn];
void build(int st[][maxn],bool tp){
	for(int i=1;(1<<i)<=n;i++) for(int j=1;j+(1<<i)-1<=n;j++)
		if(tp) st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		else st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int query(int st[][maxn],bool tp,int l,int r){
	int k=lg[r-l+1];
	if(tp) return max(st[k][l],st[k][r-(1<<k)+1]);
	else return min(st[k][l],st[k][r-(1<<k)+1]);
}
int t[40][maxn],L[40][20][maxn],R[40][20][maxn];
pair<int,int> calc(int k,int l,int r){
	if(l==r) return {t[k][r],t[k][r]};
	return {query(L[k],0,l,r-1),query(R[k],1,l,r-1)};
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) mn[0][i]=mx[0][i]=a[i];
	build(mn,0);
	build(mx,1);
	for(int i=1;i<=n;i++) t[0][i]=a[i];
	for(int i=1;i<n;i++){
		L[0][0][i]=min(a[i],a[i+1]);
		R[0][0][i]=max(a[i],a[i+1]);
	}
	build(L[0],0);
	build(R[0],1);
	for(int i=1;i<40;i++){
		for(int j=1;j<=n;j++) t[i][j]=t[i-1][t[i-1][j]];
		for(int j=1;j<n;j++){
			auto p=calc(i-1,L[i-1][0][j],R[i-1][0][j]);
			L[i][0][j]=p.first;
			R[i][0][j]=p.second;
		}
		build(L[i],0);
		build(R[i],1);
	}
	while(m--){
		int l,r;
		l=read();
		r=read();
		if(l==1&&r==n){
			printf("0\n");
			continue;
		}
		ll ans=0;
		for(int i=39;i>=0;i--){
			auto p=calc(i,l,r);
			if(p!=pair<int,int>(1,n)){
				ans|=1ll<<i;
				l=p.first;
				r=p.second;
			}
		}
		printf("%lld\n",ans==(1ll<<40)-1?-1:ans+1);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}
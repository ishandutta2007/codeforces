#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 200005
#define ll long long
#define mod 998244353
int n,_n;
int px[MN],py[MN],pp[MN];
int dx[MN],tx,dy[MN],ty;
int x[MN],y[MN];
int v[MN],b[MN];
inline void add(int i){if(!v[i])for(v[i]=1;i<=tx;i+=i&-i)++b[i];}
inline int _q(int i){int a=0;for(;i;i-=i&-i)a+=b[i];return a;}
inline int qur(int l,int r){return _q(r)-_q(l-1);}
ll ans;
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d",px+i,py+i),dx[i]=px[i],dy[i]=py[i];
	sort(dx+1,dx+n+1),tx=unique(dx+1,dx+n+1)-dx-1;
	sort(dy+1,dy+n+1),ty=unique(dy+1,dy+n+1)-dy-1;
	F(i,1,n)
		px[i]=lower_bound(dx+1,dx+tx+1,px[i])-dx,
		py[i]=lower_bound(dy+1,dy+ty+1,py[i])-dy,
		pp[i]=i;
	sort(pp+1,pp+n+1,[](int i,int j){return py[i]==py[j]?px[i]<px[j]:py[i]>py[j];});
	F(i,1,n)if(px[pp[i]]!=px[pp[i-1]]||py[pp[i]]!=py[pp[i-1]])x[++_n]=px[pp[i]],y[_n]=py[pp[i]];
	n=_n;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&y[j+1]==y[i])++j;
		for(int k=i;k<=j;++k)add(x[k]);
		ll cnt=qur(1,tx);
		ans+=cnt*(cnt+1)/2;
		int lstp=0;
		for(int k=i;k<=j;++k){
			cnt=qur(lstp+1,x[k]-1);
			ans-=cnt*(cnt+1)/2;
			lstp=x[k];
		}
		cnt=qur(lstp+1,tx);
		ans-=cnt*(cnt+1)/2;
	}printf("%lld\n",ans);
	return 0;
}
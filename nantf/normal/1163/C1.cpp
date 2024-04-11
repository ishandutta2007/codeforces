#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1010;
const double eps=1e-8;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct line{
	double k,b;
	bool operator<(const line &l)const{
		if(fabs(k-l.k)>eps) return k<l.k;
		return b<l.b;
	}
	bool operator==(const line &l)const{
		return fabs(k-l.k)<eps && fabs(b-l.b)<eps;
	}
}l[maxn*maxn];
int n,x[maxn],y[maxn],m,cnt[20020],ccc;
ll ans;
int main(){
	n=read();
	FOR(i,1,n) x[i]=read(),y[i]=read();
	FOR(i,1,n) FOR(j,i+1,n){
		if(x[i]==x[j]){
			cnt[x[i]+10000]++;
			if(cnt[x[i]+10000]==1) ccc++;
			continue;
		}
		double k=1.0*(y[i]-y[j])/(x[i]-x[j]);
		l[++m]=(line){k,y[i]-k*x[i]};
	}
	sort(l+1,l+m+1);
	m=unique(l+1,l+m+1)-l-1;
	ans=1ll*m*(m-1)/2+1ll*m*ccc;
	for(int ll=1,rr;ll<=m;ll=rr+1){
		rr=ll;
		while(rr<=m && fabs(l[ll].k-l[rr].k)<eps) rr++;
		rr--;
		ans-=1ll*(rr-ll+1)*(rr-ll)/2;
	}
	cout<<ans<<endl;
}
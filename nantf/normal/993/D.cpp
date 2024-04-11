#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct item{
	int a,b;
	bool operator<(const item &i)const{
		return a<i.a;
	}
}it[55];
int n,a[55],b[55],rnk[55],pre[55];
double w[55],s[55][55],f[55][55];
vector<double> vec[55];
bool check(double x){
	FOR(i,1,n) FOR(j,0,n) f[i][j]=-1e18;
	double ans1=0,ans2=-1e18;
	FOR(i,1,n) ans1+=w[i]=a[i]-x*b[i];
	FOR(i,1,rnk[n]) vec[i].clear();
	FOR(i,1,n) vec[rnk[i]].push_back(w[i]);
	FOR(i,1,rnk[n]){
		sort(vec[i].begin(),vec[i].end(),greater<double>());
		FOR(j,1,vec[i].size()) s[i][j]=s[i][j-1]+vec[i][j-1];
	}
	FOR(i,1,rnk[n]) pre[i]=pre[i-1]+vec[i].size();
	FOR(i,0,min(vec[rnk[n]].size(),vec[rnk[n]-1].size())) f[rnk[n]-1][i]=s[rnk[n]-1][i];
	ROF(i,rnk[n]-2,1) FOR(j,0,pre[rnk[n]-1]-pre[i]) FOR(k,0,min(n-pre[i]-2*j,(int)vec[i].size()))
		f[i][j+k]=max(f[i][j+k],f[i+1][j]+s[i][k]);
	FOR(i,0,pre[rnk[n]-1]) ans2=max(ans2,f[1][i]);
	return ans1<=ans2;
}
int main(){
	n=read();
	FOR(i,1,n) it[i].a=read();
	FOR(i,1,n) it[i].b=read();
	sort(it+1,it+n+1);
	FOR(i,1,n) a[i]=it[i].a,b[i]=it[i].b;
	rnk[1]=1;
	FOR(i,2,n) rnk[i]=rnk[i-1]+(a[i]!=a[i-1]);
	if(rnk[n]==1){
		ll as=0,bs=0;
		FOR(i,1,n) as+=a[i],bs+=b[i];
		printf("%.0lf\n",ceil(1000.0*as/bs));
		return 0;
	}
	double l=0,r=1e8;
	while(r-l>1e-8){
		double mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%.0lf\n",ceil(l*1000));
}
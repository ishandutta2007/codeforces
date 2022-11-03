#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
double a[2010],b[2010],c[2010];
struct qaq{double f;int g;};
qaq f[2010];
qaq operator+(const qaq&a,const qaq&b){return{a.f+b.f,a.g+b.g};}
bool operator<(const qaq&a,const qaq&b){
	if(fabs(a.f-b.f)<1e-6)return a.g>b.g;
	else return a.f<b.f;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),A=gi(),B=gi();
	for(int i=1;i<=n;++i)scanf("%lf",&a[i]);
	for(int i=1;i<=n;++i)scanf("%lf",&b[i]),c[i]=a[i]+(1-a[i])*b[i];
	double l=-233333,r=233333,mid,ans=0;
	while(r-l>1e-7){
		mid=(l+r)*0.5;
		for(int i=0;i<=B;++i)f[i]={0,0};
		for(int i=1;i<=n;++i){
			for(int j=B;j;--j)f[j]=std::max(std::max(f[j],f[j]+qaq{a[i]-mid,1}),std::max(f[j-1]+qaq{b[i],0},f[j-1]+qaq{c[i]-mid,1}));
			f[0]=std::max(f[0],f[0]+qaq{a[i]-mid,1});
		}
		if(f[B].g<=A)ans=std::max(ans,f[B].f+mid*f[B].g),r=mid;else l=mid;
	}
	printf("%.6lf\n",std::max(ans,f[B].f+mid*A));
	return 0;
}
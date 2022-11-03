// It is made by XZZ
#include<cstdio>
#include<algorithm>
#define il inline
#define rg register
#define vd void
#define sta static
#define int long long
#define db double
using namespace std;
il int gi(){
	rg int x=0,f=1;rg char ch=getchar();
	while(ch<'0'||ch>'9')f=ch=='-'?-1:f,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
struct afdfd{db a,t;}s[200001];
int n,T;
int a[200001],t[200001];
il bool operator <(const afdfd&a,const afdfd&b){return a.t<b.t;}
main(){
	#ifdef xzz
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	#endif
	n=gi();T=gi();
	for(rg int i=1;i<=n;++i)s[i].a=gi();
	for(rg int i=1;i<=n;++i)s[i].t=gi();
	std::sort(s+1,s+n+1);
	for(rg int i=1;i<=n;++i)a[i]=s[i].a,t[i]=s[i].t;
	int tot=0,sum=0,mn=1e18,mx=-1e18;
	for(rg int i=1;i<=n;++i){
		tot+=a[i]*t[i];sum+=a[i];
		mn=min(mn,t[i]);mx=max(mx,t[i]);
	}
	if(mx<T||mn>T){puts("0");return 0;}
	int rr=n;
#define mid ((l+r)*0.5)
	while(tot>T*sum){
		if(tot-a[rr]*t[rr]>(sum-a[rr])*T)tot-=a[rr]*t[rr],sum-=a[rr],--rr;
		else{
			db l=0,r=a[rr];
			while(r-l>=1e-10)((tot-mid*t[rr])>(sum-mid)*T)?l=mid:r=mid;
			printf("%.15lf\n",sum-l);
			return 0;
		}
	}
	int ll=1;
	while(tot<T*sum){
		if(tot-a[ll]*t[ll]<(sum-a[ll])*T)tot-=a[ll]*t[ll],sum-=a[ll],++ll;
		else{
			db l=0,r=a[ll];
			while(r-l>=1e-10)((tot-mid*t[ll])<(sum-mid)*T)?l=mid:r=mid;
			printf("%.15lf\n",sum-l);
			return 0;
		}
	}
	printf("%.15lf\n",1.0*sum);
	return 0;
}
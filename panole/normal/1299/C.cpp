#include<bits/stdc++.h>
using namespace std;

const long double eps=1e-12;
int n,a[1000010],sta[1000010],tp;
long double ans[1000010],p[1000010];
long long sum[1000010];

int main()
{
	scanf("%d",&n),sum[0]=0;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	sta[tp=1]=1,p[1]=0;
	for (int i=2; i<=n; i++)
	{
		while (tp)
		{
			if (sum[i]-1ll*i*p[tp]<=sum[sta[tp]]-1ll*sta[tp]*p[tp]) {tp--; continue;}
			p[tp+1]=(long double)(sum[i]-sum[sta[tp]])/(i-sta[tp]);
			sta[++tp]=i; break;
		}
		if (!tp) sta[++tp]=i,p[tp]=0;
	}
	p[tp+1]=1000001;
	for (int i=1,la=0; i<=tp; i++)
		if (sum[sta[i]]-sta[i]*p[i+1]-eps<=sum[la]-la*p[i+1]) 
		{
			for (int j=la+1; j<=sta[i]; j++) ans[j]=(long double)(sum[sta[i]]-sum[la])/(sta[i]-la);
			la=sta[i];
		}
	for (int i=1; i<=n; i++) printf("%.10lf\n",(double)ans[i]);
	return 0;
}

//sum[i]-1ll*i*p<=sum[t]-1ll*t*p
//sum[i]-sum[t]<=1ll*i*p-1ll*t*p
//p>=(sum[i]-sum[t])/(i-t)

//sum[r]-sum[l-1]<=(r-l+1)*mid
//sum[r]-r*mid<=sum[l-1]+(-l+1)*mid

//sum-i*mid
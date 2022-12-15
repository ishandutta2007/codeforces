#include<cstdio>
#include<cstring>

long long y,x,f,t,t0,a1,t1,p1,a2,t2,p2,ff,tt,now,ans,b,tmp;

long long getmin(long long a,long long b) {return a<b?a:b;}

int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&f,&t,&t0,&a1,&t1,&p1,&a2,&t2,&p2);
	y=f/a1; if (f%a1!=0) y++; ans=1e18; ff=f; tt=t;
	for (long long i=0; i<=y; i++)
	{
		f=ff; t=tt; now=i*p1;
		if (i*a1>f) b=f; else b=i*a1;
		if (b==f) 
		{
			if (b*t1>t) break;
			ans=getmin(ans,now);
			break;
		}
		f-=b; t-=i*t1*a1;
		if (t<0) continue;
		if (t2>=t0)
		{
			if (t/t0<f) continue;
			ans=getmin(ans,now);
			continue;
		}
		if (t/t2<f) continue;
		if (f*t0<=t) {ans=getmin(ans,now); continue;}
		x=t2*(f*t0-t)/(t0-t2);
		x-=x%t2; if (x>0) x-=t2;
		while (x/t2+(t-x)/t0<f) x+=t2;
		b=x/t2;
		if (b%a2==0) b=b/a2; else b=b/a2+1;
		now+=b*p2;
		ans=getmin(ans,now);
	}
	tmp=a1; a1=a2; a2=tmp;
	tmp=t1; t1=t2; t2=tmp;
	tmp=p1; p1=p2; p2=tmp;
	y=f/a1; if (f%a1!=0) y++; ff=f; tt=t;
	for (long long i=0; i<=y; i++)
	{
		f=ff; t=tt; now=i*p1;
		if (i*a1>f) b=f; else b=i*a1;
		if (b==f) 
		{
			if (b*t1>t) break;
			ans=getmin(ans,now);
			break;
		}
		f-=b; t-=i*t1*a1;
		if (t<0) continue;
		if (t2>=t0)
		{
			if (t/t0<f) continue;
			ans=getmin(ans,now);
			continue;
		}
		if (t/t2<f) continue;
		if (f*t0<=t) {ans=getmin(ans,now); continue;}
		x=t2*(f*t0-t)/(t0-t2);
		x-=x%t2; if (x>0) x-=t2;
		while (x/t2+(t-x)/t0<f) x+=t2;
		b=x/t2;
		if (b%a2==0) b=b/a2; else b=b/a2+1;
		now+=b*p2;
		ans=getmin(ans,now);
	}
	if (ans<1e18) printf("%I64d\n",ans); else printf("-1\n");
	return 0;
}
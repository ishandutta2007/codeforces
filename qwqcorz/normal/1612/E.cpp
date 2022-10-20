#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct node
{
	int m,k;
}a[N];
int tot[N],b[N],p[N];
void GreenDay()
{
	double ans=0;
	vector<int>out;
	int n=read();
	for (int i=1;i<=n;i++) a[i].m=b[i]=read(),a[i].k=read();
	sort(b+1,b+1+n);
	int cnt=unique(b+1,b+1+n)-b-1;
	for (int i=1;i<=n;i++) a[i].m=lower_bound(b+1,b+1+cnt,a[i].m)-b;
	for (int i=1;i<=n;i++) tot[a[i].m]+=a[i].k;
	sort(p+1,p+1+cnt,[&](int x,int y){return tot[x]>tot[y];});
	for (int i=1,sum=0;i<=cnt;i++)
	{
		sum+=tot[p[i]];
		ans=max(ans,1.0*sum/max(i,20LL));
	}
	for (int i=1,sum=0;i<=cnt;i++)
	{
		sum+=tot[p[i]];
		if (ans==1.0*sum/max(i,20LL))
		{
			for (int j=1;j<=i;j++) out.push_back(p[j]);
			break;
		}
	}
	for (int k=1;k<=min(20LL,cnt);k++)
	{
		memset(tot,0,sizeof(tot));
		for (int i=1;i<=n;i++) tot[a[i].m]+=a[i].k>=k?k:a[i].k;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		for (int j=1;j<=cnt;j++)
		{
			q.push(make_pair(tot[j],j));
			if ((int)q.size()>k) q.pop();
		}
		double now=0;
		vector<int>tmp;
		while (!q.empty()) now+=q.top().first,tmp.push_back(q.top().second),q.pop();
		now/=k;
		if (now>ans)
		{
			ans=now;
			out=tmp;
		}
	}
	print(out.size());
	for (int i:out) print(b[i],' ');
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}
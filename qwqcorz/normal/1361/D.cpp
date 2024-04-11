#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int n,k;
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
map<pair<int,int>,vector<double>>mp;
double delta(vector<double>&a,vector<double>&s,int p)
{
	if (p<=k/2) return a[(int)a.size()-p]*(k-p-p+1);
		   else return a[p-k/2-1]*(k-k/2*2+1)-s[p-k/2-1]*2;
//		   else return s[p-k/2-1]-a[p-k/2-1]*(p-k/2)+a[p-k/2-1]*(k-k/2*2);
}

signed main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read(),g=gcd(abs(x),abs(y));
		if (x==0&&y==0) continue;
		double dis=sqrt(1LL*x*x+1LL*y*y);
		x/=g,y/=g,mp[{x,y}].push_back(dis);
	}
	vector<int>p;
	vector<vector<double>>a,s;
	priority_queue<pair<double,int>>q;
	for (auto [x,b]:mp)
	{
		sort(b.begin(),b.end());
		auto c=b;
		for (int i=1;i<(int)b.size();i++) c[i]+=c[i-1];
//		for (int i=(int)b.size()-1;i>=1;i--) c[i]-=c[i-1];
//		for (int i=1;i<(int)b.size();i++) c[i]=c[i]*i+c[i-1];
		q.push({delta(b,c,1),q.size()});
		a.push_back(b);
		s.push_back(c);
		p.push_back(0);
	}
	double ans=0,sum=0;
	for (int t=1;t<=min(k,n-1);t++)
	{
		auto [d,now]=q.top(); q.pop();
		sum+=d;
		if (++p[now]<(int)a[now].size()) q.push({delta(a[now],s[now],p[now]+1),now});
		if (t>=k-1) ans=max(ans,sum);
	}
	printf("%.10lf\n",ans);
	
	return 0;
}
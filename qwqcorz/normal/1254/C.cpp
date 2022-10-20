#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int Q(int opt,int i,int j,int k)
{
	cout<<opt<<' '<<i<<' '<<j<<' '<<k<<endl;
	return read();
}
int dis[N],p[N];
bool cmp(int x,int y)
{
	return dis[x]<dis[y];
}
stack<int>q1;
queue<int>q2;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),ans=2,cnt=0;
	for (int i=3;i<=n;i++) if (Q(2,1,ans,i)<0) ans=i;
	for (int i=2;i<=n;i++) if (i!=ans) p[++cnt]=i;
	for (int i=1;i<=cnt;i++) dis[p[i]]=Q(1,1,ans,p[i]);
	sort(p+1,p+1+cnt,cmp);
	q2.push(1);
	q2.push(ans);
	for (int i=1;i<cnt;i++)
	if (Q(2,1,p[i],p[cnt])<0) q1.push(p[i]);
						 else q2.push(p[i]);
	q2.push(p[cnt]);
	putchar('0');
	while (!q2.empty()) cout<<' '<<q2.front(),q2.pop();
	while (!q1.empty()) cout<<' '<<q1.top(),q1.pop();
	cout<<endl;
		
	return 0;
}
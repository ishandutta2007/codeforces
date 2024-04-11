#include<bits/stdc++.h>
#define int long long
using namespace std;

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
int a[15],pw[20];
void Multi_test_no_horses()
{
	int n=read(),k=read()+1;
	for (int i=1;i<=n;i++) a[i]=read();
	a[n+1]=18;
	vector<int>ans;
	for (int i=1;i<=n;i++)
	{
		if (!k) break;
		int tmp=min(k,pw[a[i+1]-a[i]]-1);
		k-=tmp;
		ans.push_back(tmp);
	}
	reverse(ans.begin(),ans.end());
	for (int i:ans) write(i);
	putchar('\n');
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	for (int i=pw[0]=1;i<=18;i++) pw[i]=pw[i-1]*10;
//	int T=1;
	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}
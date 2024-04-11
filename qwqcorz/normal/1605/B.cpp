#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

int get()
{
	char c=getchar();
	while (c<'0'||'1'<c) c=getchar();
	return c-'0';
}
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
int a[N];
void Multi_test_no_horses()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=get();
	int l=1,r=n;
	vector<int>A,B;
	while (l<=r)
	{
		while (l<=r&&a[l]==0) l++;
		while (l<=r&&a[r]==1) r--;
		if (l<=r) A.push_back(l++),B.push_back(r--);
	}
	if (A.empty()) return puts("0"),void();
	puts("1");
	print(A.size()+B.size(),' ');
	reverse(B.begin(),B.end());
	for (int i:A) print(i,' ');
	for (int i:B) print(i,' ');
	puts("");
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}
// cwt random_shuffle OI  
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7;

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
unordered_map<int,vector<int>>mp;
vector<int>a;
bool check(int x)
{
	int n=0;
	static int a[10];
	while (x) a[++n]=x%10,x/=10;
	for (int i=1;i<n;i++) if (a[i]==a[i+1]) return 0;
	for (int i=2;i<n;i++) if ((a[i]<a[i-1])!=(a[i]<a[i+1])) return 0;
	return 1;
}
int get(int x,int y,int z) {return x*100+y*10+z;}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),k=read();
	for (int i=1;i<N;i++)
	if (check(i))
	{
		a.push_back(i);
		if (i%n==0&&!--k) return print(i),0;
		if (i>(int)1e5)
		{
			int x=i/1000000%10,y=i/100000%10,z=i/10000%10;
			if ((y<x)==(y<z)) mp[get(i%n,x<y,x)].push_back(i);
		}
	}
	for (int i:a)
	for (int j=0;j<=9;j++)
	if (i%10!=j&&(i<10||(i%10<i/10%10)==(i%10<j)))
	{
		int x=get((n-i*N%n)%n,j<i%10,j);
		if (!mp.count(x)) continue;
		if ((int)mp[x].size()>=k) return print(i*N+mp[x][k-1]),0;
		k-=mp[x].size();
	}
	puts("-1");
	
	return 0;
}
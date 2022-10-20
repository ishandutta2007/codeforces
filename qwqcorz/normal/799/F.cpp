#include<bits/stdc++.h>
#define ull unsigned long long
#define tot first
#define sum second
#define mk make_pair
using namespace std;
const ull N=2e5+5;

inline ull read()
{
	register ull s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register ull x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
inline void print(const register ull x,const register char c='\n')
{
	write(x);
	putchar(c);
}
ull random()
{
	return (ull)RAND_MAX*RAND_MAX*RAND_MAX*rand()+
		   (ull)RAND_MAX*RAND_MAX*rand()+
		   (ull)RAND_MAX*rand()+
		   (ull)rand();
}
map<ull,pair<ull,ull> >mp;
ull a[N],b[N],c[N];

int main()
{
	srand(time(0)*233);
	mp.clear();
	ull m=read(),n=read(),ans=0;
	for (ull i=1;i<=m;i++)
	{
		ull l=read(),r=read(),val=random();
		a[l+1]^=val;
		a[r+1]^=val;
		b[l]++;
		b[r+1]--;
	}
	for (ull i=1;i<=n;i++) b[i]+=b[i-1];
	for (ull i=1;i<=n;i++) a[i]^=a[i-1];
	for (ull i=1;i<=n;i++) a[i]^=a[i-1];
	for (ull i=1;i<=n;i++)
	{
//		print(a[i]);
		pair<ull,ull>now=mp[a[i]];
		now.tot++;
		now.sum+=i-1;
//		print(now.tot,' ');
//		print(now.sum);
		mp[a[i]]=now;
		ans+=now.tot*i-now.sum;
	}
	for (ull i=1;i<=n;i++)
	if (b[i]==0) c[i]=c[i-1]+1;
			else c[i]=0;
	for (ull i=1;i<=n;i++) ans-=c[i]*(c[i]+1)/2;
	print(ans);

	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const ll Add=1145141ll;
const ll Mod=998244353ll;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
char a[N],b[N],c[N];
struct Hash
{
	int n;
	ll h[N],Pow[N];
	Hash(){}
	Hash(char *a)
	{
		h[0]=0;
		Pow[0]=1;
		n=strlen(a+1);
		for (int i=1;i<=n;i++) h[i]=(h[i-1]*27ll+a[i]-'a'+1ll+Add)%Mod;
		for (int i=1;i<=n;i++) Pow[i]=Pow[i-1]*27ll%Mod;
	}
	ll get(int l,int r)
	{
		return (h[r]-h[l-1]*Pow[r-l+1]%Mod+Mod)%Mod;
	}
}A,B;
bool have(char *a,char *b)
{
	int n=strlen(a+1),m=strlen(b+1);
	if (n<m) return 0;
	A=Hash(a);
	B=Hash(b);
	for (int i=1;i+m-1<=n;i++)
	if (A.get(i,i+m-1)==B.get(1,m))
	return 1;
	return 0;
}
int solve1(char *a)
{
	return strlen(a+1);
}
char tmp0[N],tmp[N];
void merge(char *a,char *b,char *ans)
{
	int n=strlen(a+1),m=strlen(b+1),cnt=0,Max=0;
	A=Hash(a);
	B=Hash(b);
	for (int i=1;i<=n&&i<=m;i++)
	if (A.get(n-i+1,n)==B.get(1,i))
	Max=max(Max,i);
	for (int i=1;i<=n;i++) ans[++cnt]=a[i];
	for (int i=Max+1;i<=m;i++) ans[++cnt]=b[i];
	ans[cnt+1]='\0';
}
int solve2(char *a,char *b)
{
	if (have(a,b)) return solve1(a);
	if (have(b,a)) return solve1(b);
	merge(a,b,tmp);
	return strlen(tmp+1);
}
#define super_solve2(a,b) min(solve2(a,b),solve2(b,a))
int solve3(char *a,char *b,char *c)
{
	if (have(a,b)) return super_solve2(a,c);
	if (have(a,c)) return super_solve2(a,b);
	if (have(b,a)) return super_solve2(b,c);
	if (have(b,c)) return super_solve2(b,a);
	if (have(c,a)) return super_solve2(c,b);
	if (have(c,b)) return super_solve2(c,a);
	int ret=N;
//		merge(a,b,tmp0);
//		merge(tmp0,c,tmp);
//		ret=min(ret,(int)strlen(tmp+1));
	char *p[3]={a,b,c};
	sort(p,p+3);
	do
	{
		merge(p[0],p[1],tmp0);
		merge(tmp0,p[2],tmp);
		ret=min(ret,(int)strlen(tmp+1));
	}while (next_permutation(p,p+3));
	return ret;
}

signed main()
{
	scanf("%s%s%s",a+1,b+1,c+1);
//	merge(a,b,tmp);
//	for (int i=1;i<=strlen(a+1);i++) putchar(a[i]);puts("");
//	for (int i=1;i<=strlen(b+1);i++) putchar(b[i]);puts("");
//	for (int i=1;i<=strlen(tmp+1);i++) putchar(tmp[i]);
	print(solve3(a,b,c));
//	merge(a,b,tmp);
//	for (int i=1;i<=strlen(a+1);i++) putchar(a[i]);puts("");
//	for (int i=1;i<=strlen(b+1);i++) putchar(b[i]);puts("");
//	for (int i=1;i<=strlen(tmp+1);i++) putchar(tmp[i]);

	return 0;
}
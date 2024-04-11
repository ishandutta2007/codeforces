#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+5;

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
struct node{int l,r;};
vector<node>a;
int b[N],c[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int h=read(),q=read(),cnt=0,ans=0;
	for (int i=1;i<=q;i++)
	{
		int d=read(),l=read(),r=read(),Ans=read();
		int L=1LL<<(d-1),R=(1LL<<d)-1;
		l=max(l,L),r=min(r,R);
		L=1LL<<(h-1),R=(1LL<<h)-1;
		l*=1LL<<(h-d),r=r*(1LL<<(h-d))+(1LL<<(h-d))-1;
		if (Ans) a.push_back((node){b[++cnt]=l,b[++cnt]=r+1});
		else
		{
			if (l>L) a.push_back((node){b[++cnt]=L,b[++cnt]=l-1+1});
			if (r<R) a.push_back((node){b[++cnt]=r+1,b[++cnt]=R+1});
		}
	}
	b[++cnt]=1;
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (node &i:a)
		i.l=lower_bound(b+1,b+1+cnt,i.l)-b,
		i.r=lower_bound(b+1,b+1+cnt,i.r)-b;
	for (node i:a) c[i.l]++,c[i.r]--;
	for (int i=1;i<=cnt;i++) c[i]+=c[i-1];
	for (int i=1;i<=cnt;i++) if (c[i]==q) ans+=b[i+1]-b[i];
	if (ans==0) puts("Game cheated!");
	else if (ans>1) puts("Data not sufficient!");
	else for (int i=1;i<=cnt;i++) if (c[i]==q) print(b[i]);
	
	return 0;
}
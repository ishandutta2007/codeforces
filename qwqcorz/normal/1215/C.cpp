#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1e3;

inline int read()
{
    int s=0;
    char c=getchar(),lc='+';
    while (c<'0'||c>'9') lc=c,c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return lc=='-'?-s:s;
}
void write(int n)
{
    if (n<0)
    {
        putchar('-');
        n=abs(n);
    }
    if (n<10)
    {
        putchar(n+'0');
        return;
    }
    write(n/10);
    putchar(n%10+'0');
}
void print(int a,int b)
{
	write(a);
	putchar(' ');
	write(b);
	putchar('\n');
}
pair<int,int>ans[4*N];
int n,ab[N],ba[N],cnt1=0,cnt2=0,cnt=0;
bool s[N],t[N];
void readln(bool *a)
{
	for (int i=1;i<=n;i++)
	{
		char c=getchar();
		while (c!='a'&&c!='b') c=getchar();
		if (c=='a') a[i]=0;
			   else a[i]=1;
	}
}

int main()
{
	n=read();
	readln(s);
	readln(t);
	for (int i=1;i<=n;i++)
	{
		if (s[i]==0&&t[i]==1) ab[++cnt1]=i;
		if (s[i]==1&&t[i]==0) ba[++cnt2]=i;
	}
	if (cnt1%2!=cnt2%2)
	{
		puts("-1");
		return 0;
	}
	for (int i=1;i<cnt1;i+=2) ans[++cnt]=make_pair(ab[i],ab[i+1]);
	for (int i=1;i<cnt2;i+=2) ans[++cnt]=make_pair(ba[i],ba[i+1]);
	if (cnt1&1)
	{
		int w1=ab[cnt1],w2=ba[cnt2];
		ans[++cnt]=make_pair(w1,w1);
		ans[++cnt]=make_pair(w1,w2);
	}
	write(cnt);
	putchar('\n');
	for (int i=1;i<=cnt;i++) print(ans[i].first,ans[i].second);

	return 0;
}
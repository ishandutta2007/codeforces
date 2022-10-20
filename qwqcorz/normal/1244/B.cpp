#include<bits/stdc++.h>
using namespace std;
const int N=2e3;

inline int read()
{
    int s=0;
    char c=getchar(),lc='+';
    while (c<'0'||c>'9') lc=c,c=getchar();
    while (c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
    return lc=='-'?-s:s;
}
void write(int x)
{
    if (x<0)
    {
        putchar('-');
        x=-x;
    }
    if (x<10)
    {
        putchar(x+'0');
        return;
    }
    write(x/10);
    putchar(x%10+'0');
}
bool a[N];
int l[N],r[N];

int main()
{
	int t=read();
	while (t--)
	{
		int n=read(),ans=n;
		l[0]=0;
		r[n+1]=0;
		for (int i=1;i<=n;i++)
		{
			char c=getchar();
			if (c!='0'&&c!='1') c=getchar();
			a[i]=c-'0';
		}
		for (int i=1;i<=n;i++) l[i]=l[i-1]+1+a[i];
		for (int i=n;i>=1;i--) r[i]=r[i+1]+1+a[i];
		for (int i=1;i<=n;i++)
		{
			ans=max(ans,l[i]+r[i+1]);
			if (a[i])
			{
				ans=max(ans,i*2);
				ans=max(ans,n+1);
				ans=max(ans,(n-i+1)*2);
			}
		}
		write(ans);
		putchar('\n');
	}

	return 0;
}
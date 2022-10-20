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
bool a[N];

int main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++)
	{
		char c=getchar();
		while (c<'a'||'b'<c) c=getchar();
		a[i]=c-'a';
	}
	for (int i=1;i<=n;i+=2)
	if (a[i]==a[i+1])
	{
		a[i]=!a[i];
		ans++;
	}
	write(ans);
	putchar('\n');
	for (int i=1;i<=n;i++) putchar(a[i]+'a');

	return 0;
}
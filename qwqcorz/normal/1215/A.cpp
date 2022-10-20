#include<bits/stdc++.h>
using namespace std;

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

int main()
{
	int n=read(),m=read(),k1=read(),k2=read(),num=read();
	if (k1>k2)
	{
		swap(n,m);
		swap(k1,k2);
	}
	if (n*(k1-1)+m*(k2-1)>=num) write(0);
						   else write(min(num-n*(k1-1)-m*(k2-1),n+m));
	putchar(' ');
	if (n*k1>num) write(num/k1);
	else if (n*k1+m*k2>num) write(n+(num-n*k1)/k2);
	else write(n+m);

	return 0;
}
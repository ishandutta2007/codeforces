#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,m,f[N],g[N];

char a[N],b[N];

int main()
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	int j=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[j])
			f[i]=f[i-1]+1,j++;
		else
			f[i]=f[i-1];
	}
	j=m;
	for(int i=n;i>=1;i--)
	{
		if(a[i]==b[j])
			g[i]=g[i+1]+1,j--;
		else
			g[i]=g[i+1];
	}
	int len=0;
    int pos;
    for(int i=1;i<=n;i++)
        if((f[i]+g[i])>len&&(f[i]==f[i-1]||g[i]==g[i+1]))
		{
            len=(f[i]+g[i]);
            pos=f[i];
        } 
		else 
		{
            if(f[i]+g[i+1]>len)
			{
                len=(f[i]+g[i+1]);
                pos=f[i];
            }
        }
    len=min(len,min(n,m));
    if(len==0)
	{
        puts("-");
        return 0;
    }
    for(int i=1;i<=pos;i++)
        printf("%c",b[i]);
    int k=(m-(len-pos)+1);
    for(int i=k;i<=m;i++)
        printf("%c",b[i]);
}
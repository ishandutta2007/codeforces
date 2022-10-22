// By: Little09
// Problem: CF1200E Compress Words
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1200E
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n;
const int N=2e6+5;
char a[N],b[N],c[N];
int kmp[N];
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
int lena,lenb;
int pre(int len)
{
	kmp[1]=0;
	for (int i=2;i<=len;i++)
	{
		int j=kmp[i-1];
		while (j!=0&&c[i]!=c[j+1]) j=kmp[j];
		if (c[i]==c[j+1]) j++;
		kmp[i]=j;
	}
	return kmp[len];
}
void merge()
{
	int cnt=0,w=min(lena,lenb);
	for (int i=1;i<=w;i++) c[++cnt]=b[i];
	c[++cnt]='#';
	for (int i=lena-w+1;i<=lena;i++) c[++cnt]=a[i];
	int ans=pre(cnt);
	cnt=0;
	for (int i=ans+1;i<=lenb;i++) a[++lena]=b[i];
}
int main()
{
	n=read();
	scanf("%s",a+1);
	lena=strlen(a+1);
	for (int i=2;i<=n;i++)
	{
		scanf("%s",b+1);
		lenb=strlen(b+1);
		merge();
	}
	for (int i=1;i<=lena;i++) printf("%c",a[i]);
	return 0;
}
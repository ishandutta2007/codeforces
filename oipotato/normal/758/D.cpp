#include<cstdio>
#include<iostream>
using namespace std;
long long s,ans,tmp,ss;
int n,tot,a[110],j;
char ch;
int main()
{
	scanf("%d",&n);
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar());
	for(;'0'<=ch&&ch<='9';ch=getchar())a[++tot]=ch-'0';
	s=1;ans=0;
	for(int i=tot;i>0;i--)
	{
		tmp=a[i];j=i;ss=10;for(;i>1&&ss<=n&&a[i-1]*ss+tmp<n;ss*=10)tmp=tmp+a[--i]*ss;
		for(;tmp&&!a[i];i++);if(!tmp)i=j;
		ans+=s*tmp;
		s*=n;
	}
	cout<<ans;
	return 0;
}
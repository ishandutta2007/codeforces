#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int T,a,b,c,d,e,f,ans; 
inline int read()
{
	char C;
	int F=1,ANS=0;
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
int main()
{
	T=read();
	while (T--)
	{
		a=read(),b=read(),c=read(),d=read(),e=read(),f=read();
		if (e>f) swap(e,f),swap(c,d);
		ans=0;
		for (int i=0;i<=c;i++)
		{
			int aa=a-i*e;
			if (aa<0) break;
			int j=aa/f;
			int ii=b/e;
			if (ii>c-i) ii=c-i;
			int res=b-ii*e;
			int jj=res/f;
			if (jj>d-j) jj=d-j;
			ans=max(ans,i+j+ii+jj);
		}
		cout << ans << endl;
	}
	return 0;
}
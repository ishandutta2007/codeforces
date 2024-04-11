#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int sum[N][30];
string s;
int n,m;
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
int num(int l,int r)
{
	int res=0;
	for (int i=0;i<26;i++) if (sum[r][i]-sum[l-1][i]) res++;
	return res;
}
int main()
{
	cin >> s;
	n=s.size();
	m=read();
	for (int i=0;i<n;i++) sum[i+1][s[i]-'a']=1;
	for (int i=1;i<=n;i++) for (int j=0;j<26;j++) sum[i][j]+=sum[i-1][j];
	while (m--)
	{
		int l=read(),r=read();
		if (l==r) puts("Yes");
		else if (s[l-1]!=s[r-1]) puts("Yes");
		else if (num(l,r)>=3) puts("Yes");
		else puts("No");
	}
	return 0;
}
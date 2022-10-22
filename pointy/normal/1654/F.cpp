// By: Little09
// Problem: CF1654F Minimal String Xoration
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1654F
// Memory Limit: 500 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int a[N],v[N];
int t[N],n,m;

int l;
bool cmp(int x,int y)
{
	if (v[x]==v[y]) return v[x^l]<v[y^l];
	return v[x]<v[y];
}

int main()
{
	scanf("%d",&n);
	scanf("%s",&s);
	m=(1<<n);
	for (int i=0;i<m;i++) a[i]=i;
	for (int i=0;i<m;i++) v[i]=s[i]-'a';
	sort(a,a+m,cmp);
	for (int i=1;i<=n;i++)
	{
		l=(1<<(i-1));
		sort(a,a+m,cmp);
		int cnt=0;
		for (int j=0;j<m;j++)
		{
			if (j==0||cmp(a[j-1],a[j])) t[a[j]]=++cnt;
			else t[a[j]]=cnt;
		}
		for (int j=0;j<m;j++) v[j]=t[j];
	}
	int ans=a[0];
	for (int i=0;i<m;i++) printf("%c",s[i^ans]);
	return 0;
}
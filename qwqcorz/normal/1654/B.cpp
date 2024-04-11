#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N];
void GreenDay()
{
	scanf("%s",a+1);
	int n=strlen(a+1),tot[26]={};
	for (int i=1;i<=n;i++) tot[a[i]-'a']++;
	for (int i=1;i<=n;i++)
	if (tot[a[i]-'a']==1)
	{
		for (int j=i;j<=n;j++) putchar(a[j]);
		puts("");
		return;
	}
	else tot[a[i]-'a']--;
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}
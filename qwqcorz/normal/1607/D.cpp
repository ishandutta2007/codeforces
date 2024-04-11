#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
char s[N];
bool GreenDay()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	scanf("%s",s+1);
	vector<int>A,B;
	for (int i=1;i<=n;i++)
	if (s[i]=='B') A.push_back(a[i]);
			  else B.push_back(a[i]);
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int now=0;
	for (int i:A) if (++now>i) return 0;
	for (int i:B) if (++now<i) return 0;
	return 1;
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) puts(GreenDay()?"YES":"NO");
	
	return 0;
}
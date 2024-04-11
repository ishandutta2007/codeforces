#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N];

signed main()
{
	int n=read(),sum=0;
	scanf("%s",a+1);
	for (int i=1;i<=n;i++) sum+=a[i]=='('?1:-1;
	if (sum) return puts("No"),0;
	int L=0,R=0;
	for (int i=1;i<=n;i++) if (a[i]==')'){L=i;break;}
	for (int i=1;i<=n;i++) if (a[i]=='(') R=i;
	if (L<R) for (int i=R-1;i>=L;i--) swap(a[i],a[i+1]);
	for (int i=1;i<=n;i++)
	if ((sum+=a[i]=='('?1:-1)<0) return puts("No"),0;
	puts("Yes");
	
	return 0;
}
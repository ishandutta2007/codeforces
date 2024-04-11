#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int sg[155];
int SG(int x)
{
    if (x<=120) return sg[x];
    return sg[x%34+2*34];
}
char a[N];
void work()
{
	int n=read(),A=0,B=0,ans=0,last=-1,len=0;
	scanf("%s",a+1);
	for (int i=1;i<=n;i++) (a[i]=='R'?A:B)++;
	if (A>B) return puts("Alice"),void();
	if (A<B) return puts("Bob"),void();
	for (int i=1;i<=n;i++)
	{
		int x=a[i]=='R';
		if (x!=last&&last>=0) len++,last=x;
						 else ans^=SG(len),len=1,last=x;
	}
	ans^=SG(len);
	puts(ans?"Alice":"Bob");
}

signed main()
{
	sg[0]=sg[1]=0;
	for (int i=2;i<=150;i++)
	{
		vector<int>vis(155);
		for (int j=1;j+1<=i;j++) vis[sg[j-1]^sg[i-j-1]]=1;
		while (vis[sg[i]]) sg[i]++;
	}
	int T=read();
	while (T--) work();
	
	return 0;
}
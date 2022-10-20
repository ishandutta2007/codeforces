#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=55;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N],b[N];
int p[26];

void GreenDay()
{
	scanf("%s%s",a,b+1);	
	for (int i=0;i<26;i++) p[a[i]-'a']=i;
	int ans=0,n=strlen(b+1);
	for (int i=1;i<n;i++) ans+=abs(p[b[i]-'a']-p[b[i+1]-'a']);
	print(ans);
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}
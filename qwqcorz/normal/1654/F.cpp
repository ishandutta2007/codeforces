#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1<<18;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char s[N+1],t[N+1];
int rk[N],p[N];
pair<int,int>tmp[N];

signed main()
{
	int n=read(),m=1<<n;
	scanf("%s",s);
	for (int i=0;i<m;i++) rk[p[i]=i]=s[i]-'a';
	for (int j=0;j<n;j++)
	{
		for (int i=0;i<m;i++) tmp[i]=make_pair(rk[i],rk[i^(1<<j)]);
		sort(p,p+m,[&](int x,int y){
			return tmp[x]<tmp[y];
		});
		for (int i=0;i<m;i++)
		if (!i||tmp[p[i]]!=tmp[p[i-1]]) rk[p[i]]=i;
								   else rk[p[i]]=rk[p[i-1]];
	}
	int x=0;
	for (int i=1;i<m;i++) if (rk[i]<rk[x]) x=i;
	for (int i=0;i<m;i++) t[i^x]=s[i];
	puts(t);
	
	return 0;
}
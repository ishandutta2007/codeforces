#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 1000005
#define MM 600005
#define ll long long
#define mod 998244353
int T,n,m;
char x[MN],y[MN];
char s[MN],t[MN];
int a[MN],b[MN],c,d;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",x+1,y+1);
		n=strlen(x+1),m=strlen(y+1);
		c=d=0;
		F(i,1,n)if(x[i]!=x[i-1])s[++c]=x[i],a[c]=1;else++a[c];
		F(i,1,m)if(y[i]!=y[i-1])t[++d]=y[i],b[d]=1;else++b[d];
		if(c!=d){puts("NO");continue;}
		int ok=1;
		F(i,1,c)if(s[i]!=t[i]||a[i]>b[i]){ok=0;break;}
		puts(ok?"YES":"NO");
	}
	return 0;
}
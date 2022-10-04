#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
char s[MN];
int main(){
	scanf("%d%s",&n,s+1);
	int mx=1;
	F(i,2,n){
		if(s[mx]>s[i])return printf("YES\n%d %d\n",mx,i),0;
		if(s[i]>s[mx])mx=i;
	}
	puts("NO");
	return 0;
}
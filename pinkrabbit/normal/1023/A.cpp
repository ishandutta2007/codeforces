#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,m;
char s[200005],t[200005];

int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	if(n>m+1) return 0*puts("NO");
	int ok=0;
	F(i,1,n) if(s[i]=='*') ok=1;
	if(!ok){
		if(n!=m) return 0*puts("NO");
		else return 0*puts(memcmp(s+1,t+1,n)?"NO":"YES");
	}
	ok=1;
	for(int i=1;s[i]!='*';++i) if(t[i]!=s[i]) ok=0;
	for(int i=n;s[i]!='*';--i) if(t[m-n+i]!=s[i]) ok=0;
	puts(ok?"YES":"NO");
	return 0;
}
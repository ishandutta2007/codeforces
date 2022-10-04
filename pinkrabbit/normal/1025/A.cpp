#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,q;
char s[100201];
int c[100001],b[100001];

int main(){
	scanf("%d",&n);
	if(n==1) return 0*puts("Yes");
	if(n>26) return 0*puts("Yes");
	scanf("%s",s+1);
	F(i,1,n) ++c[s[i]-'a'];
	int ok=0;
	F(i,0,25) if(c[i]>1) ok=1;
	puts(ok?"Yes":"No");
	return 0;
}
// Luogu
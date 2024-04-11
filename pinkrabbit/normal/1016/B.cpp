#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,m,q;
char s[1005],t[1005];
int c[1005];

int main(){
	scanf("%d%d%d",&n,&m,&q);
	scanf("%s%s",s+1,t+1);
	if(m>n) {F(i,1,q) puts("0"); return 0;}
	F(i,1,n-m+1){
		int ok=1;
		F(j,1,m) if(s[i+j-1]!=t[j]) ok=0;
		c[i]=ok;
	}
	F(Q,1,q){
		int l,r;
		scanf("%d%d",&l,&r);
		int cnt=0;
		F(i,l,r-m+1) cnt+=c[i];
		printf("%d\n",cnt);
	}
	return 0;
}
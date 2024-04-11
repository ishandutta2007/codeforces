#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
typedef long long LL;
typedef double ld;
const int INF=0x3f3f3f3f;

int n,q,m,k;
char s1[5];
char s2[7][5];

int main(){
	scanf("%s",s1);
	scanf("%s",s2[1]);
	scanf("%s",s2[2]);
	scanf("%s",s2[3]);
	scanf("%s",s2[4]);
	scanf("%s",s2[5]);
	int ok=0;
	F(i,1,5) if(s1[0]==s2[i][0]||s1[1]==s2[i][1]) ok=1;
	puts(ok?"YES":"NO");
	return 0;
}
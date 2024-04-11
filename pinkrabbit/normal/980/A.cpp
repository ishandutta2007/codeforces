#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

char str[100001];
int cnt1,c2;

int main(){
	scanf("%s",str);
	for(int i=0;str[i];++i) if(str[i]=='o') ++cnt1; else ++c2;
	if(!cnt1) puts("YES");
	else printf(c2%cnt1?"NO":"YES");
	return 0;
}
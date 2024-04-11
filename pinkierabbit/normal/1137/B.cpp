#include <bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=(a);i<=(b);++i)

typedef long long LL;
const int MN = 5000005;
const int INF = 0x3f3f3f3f;

int n, m, q, k;
char s[MN], t[MN];
int p[MN];

int main() {
	int c0=0,c1=0;
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	int k=0;
	for (int i=2;i<=m;++i){
		while(k&&t[k+1]!=t[i])k=p[k];
		if(t[k+1]==t[i])++k;
		p[i]=k;
	}
	for(int i=1;i<=n;++i)if(s[i]=='0')++c0;else ++c1;
	int j=0;
	for(int i=1;i<=n;++i){
		int c=t[j+1]-'0';
		if(c?c1:c0){
			printf("%d",c?1:0);
			--(c?c1:c0);
			if(++j==m)j=p[m];
		}else printf("%d",c?0:1);
	}
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
using namespace std;
#define ll long long
#define rt register int
#define reep(i,x,y) for(rt i=(x);i<(y);++i)
#define per(i,x,y) for(rt i=(x);i>=(y);--i)
#define rep(i,x,y) for(rt i=(x);i<=(y);++i)
#define travel(i,x) for(rt i=h[x];i;i=pre[i])
char s[2333];
bool flag;
int tot;
int main() {
	scanf("%s", s);
	for(rt i=0; s[i]; ++i){
		if(s[i]=='1') flag=1;
		if(flag && s[i]=='0') ++tot;
	}
	if(tot>=6 && flag) puts("yes"); else puts("no");
	return 0;
}
#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

char str[100001];
int len,cnt;
int vis[26];
int v2[8];

int main(){
	scanf("%s",str+1); len=strlen(str+1);
	F(i,1,len) ++vis[str[i]-'a'];
	F(i,0,25){
		if(vis[i]) v2[++cnt]=vis[i];
	}
	sort(v2+1,v2+cnt+1);
	if(cnt==1) puts("No");
	if(cnt==2){
		if(v2[1]>1) puts("Yes");
		else puts("No");
	}
	if(cnt==3){
		if(v2[3]>1) puts("Yes");
		else puts("No");
	}
	if(cnt==4){
		puts("Yes");
	}
	if(cnt>=5) puts("No");
	return 0;
}
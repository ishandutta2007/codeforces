#include<bits/stdc++.h>
using namespace std;
int n,m,pos;
char s[200020],t[200020];
int main(){
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	if(n-m>1) return puts("NO"),0;
	for(int i=1;i<=n;i++)
		if(s[i]=='*'){
			pos=i;break;
		}
	if(!pos) return puts(strcmp(s+1,t+1)?"NO":"YES"),0;
	for(int i=1;i<pos;i++)
		if(s[i]!=t[i]) return puts("NO"),0;
	for(int i=n;i>pos;i--)
		if(s[i]!=t[i-n+m]) return puts("NO"),0;
	puts("YES");
}
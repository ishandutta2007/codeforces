

// B
#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
char s[51][51];
il bool tryfill(int x,int y){
	if(s[x][y]=='.'){s[x][y]='#';return 1;}
	puts("NO");exit(0);
}
int main(){
#ifndef ONLINE_JUDGE
 	freopen("in.in","r",stdin);
 	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(int x=1;x<=n;++x)
		for(int y=1;y<=n;++y)
			if(s[x][y]=='.'){
				tryfill(x,y);
				tryfill(x+1,y);
				tryfill(x+2,y);
				tryfill(x+1,y-1);
				tryfill(x+1,y+1);
			}
	puts("YES");
	return 0;
}
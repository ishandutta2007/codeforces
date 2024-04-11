#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int main(){
	int n=gi(),k=gi(),m=0,x,y,s=0;
	for(int i=1;i<=k+1;++i){
		putchar('?');
		for(int j=1;j<=k+1;++j)if(j!=i)printf(" %d",j);
		puts("");
		fflush(stdout);
		x=gi(),y=gi();
		if(y>s)s=y,m=1;
		else if(y==s)++m;
	}
	printf("! %d\n",m);fflush(stdout);
	return 0;
}
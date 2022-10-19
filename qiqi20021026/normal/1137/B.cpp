#include<bits/stdc++.h>

using namespace std;

int n,m,f[2],nxt[1200000];
char a[1200000],b[1200000];

void gg(int x){
	if (f[x]){--f[x]; putchar(x+'0');}
	else putchar((x^1)+'0');
}

int main(){
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1); m=strlen(b+1);
	for (int i=1;i<=n;++i) ++f[a[i]-'0'];
	nxt[1]=0;
	for (int i=2,j=0;i<=m;++i){
		for (;j&&b[i]!=b[j+1];j=nxt[j]);
		if (b[i]==b[j+1]) nxt[i]=++j;
		else nxt[i]=0;
	}
	for (int i=1,j=1;i<=n;++i){
		gg(b[j]-'0');
		++j;
		if (j>m) j=nxt[m]+1;
	}
	puts("");
	
	return 0;
}
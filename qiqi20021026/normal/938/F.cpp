#include<bits/stdc++.h>

using namespace std;

#define N 6000

int n,m,f[N];
char s[N];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (m=0;1<<(m+1)<n;++m);
	for (int i=0;i<1<<m;++i) f[i]=1;
	for (int i=1;i<=n-(1<<m)+1;++i){
		char c='z';
		for (int j=0;j<1<<m;++j)
			if (f[j]) c=min(c,s[i+j]);
		putchar(c);
		for (int j=0;j<1<<m;++j)
			f[j]&=s[i+j]==c;
		for (int j=0;j<1<<m;++j)
			for (int k=0;k<m;++k)
				f[j|(1<<k)]|=f[j];
	}
	
	return 0;
}
#include<bits/stdc++.h>

char str[10000];
int i,n,A,B,C;

int main() {
	scanf("%s",str);
	n=strlen(str);
	if(str[0]!='a') {
		puts("NO");
		return 0;
	}
	for(i=0; i<n; ++i) if(str[i]=='a') ;
		else break;
	A=i;
	if(i==n||str[i]!='b') {
		puts("NO");
		return 0;
	}
	for(; i<n; ++i) if(str[i]=='b') ;
		else break;
	if(i==n||str[i]!='c') {
		puts("NO");
		return 0;
	}
	B=i-A;
	for(; i<n; ++i) if(str[i]=='c') ;
		else break;
	if(i!=n) {
		puts("NO");
		return 0;
	}
	C=n-B-A;
	if(C!=A&&C!=B) {
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}
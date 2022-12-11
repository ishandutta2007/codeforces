#include<bits/stdc++.h> 
using namespace std;
char s[10010];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	printf("%s",s);
	for(int i=n-1;i>=0;i--)
		putchar(s[i]);
	puts("");
}
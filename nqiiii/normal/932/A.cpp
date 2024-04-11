#include<cstdio>
#include<cstring>
char s[10000]; int l;
int main(){
	scanf("%s",s); l=strlen(s);
	for(int i=0;i<l;++i) printf("%c",s[i]);
	for(int i=l-1;i>=0;--i) printf("%c",s[i]);
}
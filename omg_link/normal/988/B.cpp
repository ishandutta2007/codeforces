#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define MN 100
int n;
char *s[MN+5];
bool cmp(char *a,char *b){
	return strlen(a)<strlen(b);
}
void ans(const char *s){
	printf("%s",s);
	exit(0);
}
bool ccmp(const char *a,const char *b){
	int i=0;
	while(a[i]==b[i])
		if(a[++i]=='\0')return true;
	return false;
}
bool substr(const char *a,const char *b){
	int la=strlen(a),lb=strlen(b);
	for(int i=0;i<=lb-la;i++)
		if(ccmp(a,b+i))return true;
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		s[i]=new char [MN+5];
		scanf("%s",s[i]);
	}
	std::sort(&s[1],&s[n+1],cmp);
	for(int i=2;i<=n;i++)
		if(!substr(s[i-1],s[i]))ans("NO");
	printf("YES\n");
	for(int i=1;i<=n;i++)
		printf("%s\n",s[i]);
}
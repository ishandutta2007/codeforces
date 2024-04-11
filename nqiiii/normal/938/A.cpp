#include<cstdio>
int n; char s[10000];
bool check(char c){
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y';
}
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;++i) if(!check(s[i])||!check(s[i-1])) printf("%c",s[i]);
}
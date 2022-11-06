#include<cstdio>
#include<cstring>
const int maxn=100000;
char nowch='a',s[maxn+10];
int n;
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=1;i<=n;++i) if(nowch<='z'&&s[i]<=nowch){
		s[i]=nowch; ++nowch;
	}
	if(nowch=='z'+1) printf("%s",s+1);
	else printf("-1");
}
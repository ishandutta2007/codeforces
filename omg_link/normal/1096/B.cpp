#include <stdio.h>
#define MN 200000
const int mod=998244353;
int n,ans;
char s[MN+5];
int main(){
	scanf("%d%s",&n,&s[1]);
	if(s[1]==s[n]){
		int c1=1,c2=1;
		for(int i=2;s[i]==s[i-1];i++) c1++;
		for(int i=n-1;s[i]==s[i+1];i--) c2++;
		ans=1ll*(c1+1)*(c2+1)%mod;
		printf("%d\n",ans);
	}else{
		int c1=1,c2=1;
		for(int i=2;s[i]==s[i-1];i++) c1++;
		for(int i=n-1;s[i]==s[i+1];i--) c2++;
		printf("%d\n",c1+c2+1);
	}
}
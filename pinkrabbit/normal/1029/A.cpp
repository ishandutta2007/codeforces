#include<cstdio>
#include<cstring>
int n,k; char str[60];
int main(){
	scanf("%d%d%s",&n,&k,str);
	for(int i=n-1;i;--i) if(!memcmp(str,str+n-i,i)) {printf("%s",str); while(--k) printf("%s",str+i); return 0;}
	while(k--) printf("%s",str);
	return 0;
}
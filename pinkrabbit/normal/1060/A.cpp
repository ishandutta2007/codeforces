#include<cstdio>
// from_luogu
int n,c; char str[105];
int main(){
	scanf("%d%s",&n,str);
	for(int i=0;str[i];++i) if(str[i]=='8') ++c;
	printf("%d",c<n/11?c:n/11);
	return 0;
}
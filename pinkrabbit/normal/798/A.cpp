#include<cstdio>
char str[16],len=0,l,r,sum=0;
int main(){
	scanf("%s",str);
	while(str[++len]!='\0');l=-1,r=len;
	while(++l<--r)
		if(str[l]!=str[r])++sum;
	if(sum==1||(sum==0&&len&1)) puts("YES");
	else puts("NO");
	return 0;
}
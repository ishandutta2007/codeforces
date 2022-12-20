#include <stdio.h>
#include <algorithm>
#define MN 100000
typedef long long LL;
int n,a[MN+5];
char s[MN+5];
LL f[4];
int main(){
	scanf("%d%s",&n,&s[1]);
	int okl=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(s[i]=='h'){
			if(okl==0) okl++;
			if(okl>0) f[0]+=a[i];
		}
		if(s[i]=='a'){
			if(okl==1) okl++;
			if(okl>1) f[1]+=a[i];
		}
		if(s[i]=='r'){
			if(okl==2) okl++;
			if(okl>2) f[2]+=a[i];
		}
		if(s[i]=='d'){
			if(okl==3) okl++;
			if(okl>3) f[3]+=a[i];
		}
		for(int i=1;i<4;i++)
			f[i]=std::min(f[i],f[i-1]);
	}
	if(okl!=4) puts("0");
	else{
		LL aa=0x7fffffffffffffffll;
		for(int i=0;i<4;i++)
			aa=std::min(aa,f[i]);
		printf("%lld\n",aa);
	}
}
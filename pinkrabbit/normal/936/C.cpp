#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
using namespace std;

int n;
char str1[2005],str2[2005],str3[2005],str4[2005];

int main(){
	scanf("%d%s%s",&n,str1+1,str2+1);
	memcpy(str3+1,str1+1,n);
	memcpy(str4+1,str2+1,n);
	sort(str3+1,str3+n+1);
	sort(str4+1,str4+n+1);
	if(memcmp(str3+1,str4+1,n)) {puts("-1"); return 0;}
	printf("%d\n",n*3);
	dF(i,n,1){
		int p;
		F(j,n-i+1,n) if(str1[j]==str2[i]) {p=j; break;}
		printf("%d %d 1 ",n,p-1);
		reverse(str1+p+1,str1+n+1);
		memcpy(str1+2,str1+1,p-1);
		str1[1]=str2[i];
	}
	return 0;
}
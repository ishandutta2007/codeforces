#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int a[110],b[110],c[110];
int main(){
	int k,m,n;
	int cnt;
	scanf("%d",&n);
	cnt=m=0;
	for(int i=1 ;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=0)
		  m++;
	}
	if(m == 0){
		printf("NO\n");
	}
	else {	
		for(int i=1;i<=n;i++){
		b[++cnt] = i;
		while(a[i] == 0)
		   i++;
		if(--m == 0)
            break;
		c[cnt]= i;
		}
		c[cnt]=n;
		printf("YES\n%d\n",cnt);
		for(int i=1;i<=cnt;i++){
			printf("%d %d\n",b[i],c[i]);
		}
	}
	return 0;
}
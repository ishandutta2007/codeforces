#include <stdio.h>
#define MN 100
int n,k,t=0,a[MN+5];
bool b[MN+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!b[a[i]])b[a[i]]=1,t++;
	}
	if(t<k){
		puts("NO");
	}else{
		puts("YES");
		for(int i=1;i<=n&&k>0;i++)
			if(b[a[i]])printf("%d ",i),b[a[i]]=0,k--;
	}
}
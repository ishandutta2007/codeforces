#include <stdio.h>
#define MN 10000

int n,a[MN+5];
bool ex[MN+5];

int query(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int r;
	scanf("%d",&r);
	return r;
}

void answer(){
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	fflush(stdout);
}

int main(){
	scanf("%d",&n);
	int i=1,j=2;
	for(int l=2;l<=n;){
		int a1 = query(i,j);
		int a2 = query(j,i);
		if(a1>a2){
			a[i] = a1;
			ex[a1] = true;
			i = (++l);
		}else{
			a[j] = a2;
			ex[a2] = true;
			j = (++l);
		}
	}
	int lst;
	for(int i=1;i<=n;i++){
		if(!ex[i]){
			lst = i;
			break;
		}
	}
	if(i==n+1){
		a[j] = lst;
	}else{
		a[i] = lst;
	}
	answer();
}
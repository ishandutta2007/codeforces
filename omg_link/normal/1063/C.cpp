#include <stdio.h>
int n,l=0,r=1e9;
char str[20],tp='\0';
bool samc=true;
int main(){
	scanf("%d",&n);
	int st=499999950;
	while((n--)>0){
		fflush(stdin);
		printf("%d %d\n",0,st);
		fflush(stdout);
		st+=2;
		scanf("%s",&str[1]);
		if(tp=='\0'){
			tp=str[1];
		}else if(tp!=str[1]){
			samc=false;
			break;
		}
	}
	if(!samc) st-=3;
	while((n--)>0){
		int mid=(l+r)>>1;
		fflush(stdin);
		printf("%d %d\n",1000000000,mid);
		fflush(stdout);
		scanf("%s",&str[1]);
		if(str[1]==tp) l=mid;
		else r=mid;
	}
	printf("%d %d %d %d\n",0,st,1000000000,(l+r)>>1);
}
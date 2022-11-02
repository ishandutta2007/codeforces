#include<stdio.h>
int a[111];
char in[1000];
int main(){
    int t,m,i,j;
    scanf("%d%d",&t,&m);
    int aid=1;
    while(t--){
//	for(i=0;i<m;i++
	scanf("%s",in);
	int k;
	if(in[0]=='a'){
	    scanf("%d",&k);
	    for(i=0;i<=m-k;i++){
		for(j=i;j<i+k;j++)if(a[j]!=0)break;
		if(j==i+k)break;
	    }
	    if(i<=m-k){
		printf("%d\n",aid);
		for(j=i;j<i+k;j++)a[j]=aid;
		aid++;
	    }else{
		puts("NULL");
	    }
	}else if(in[0]=='e'){
	    bool f=0;
	    scanf("%d",&k);
	    for(i=0;i<m;i++)if(a[i]&&a[i]==k){
		a[i]=0;
		f=1;
	    }
	    if(!f)puts("ILLEGAL_ERASE_ARGUMENT");
	}else{
	    for(i=0,j=0;i<m;i++)if(a[i]){
		a[j++]=a[i];
	    }
	    for(;j<m;j++)a[j]=0;
	}
    }
}
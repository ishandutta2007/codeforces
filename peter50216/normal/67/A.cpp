#include<stdio.h>
char in[1010];
int out[1010];
int main(){
    int n,i,j;
    scanf("%d",&n);
    scanf("%s",in);
    for(i=0;i<n;i++){
	if(i)printf(" ");
	int c1=0,c2=0;
	for(j=i-1;j>=0;j--){
	    if(in[j]=='R')c1++;
	    else if(in[j]=='L')break;
	}
	for(j=i+1;j<n;j++){
	    if(in[j-1]=='L')c2++;
	    else if(in[j-1]=='R')break;
	}
	printf("%d",1+(c1>c2?c1:c2));
    }
    puts("");
}
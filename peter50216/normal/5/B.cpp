#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char in[1010][1010];
int main(){
    int n=0,l=0,i,j;
    while(gets(in[n])!=NULL){
	l=max(l,(int)strlen(in[n]));
	n++;
    }
    for(i=0;i<l+2;i++)printf("*");
    puts("");
    int s=0;
    for(i=0;i<n;i++){
	printf("*");
	int k=strlen(in[i]);
	if((l-k)%2){
	    for(j=0;j<(l-k)/2+s;j++)printf(" ");
	}else{
	    for(j=0;j<(l-k)/2;j++)printf(" ");
	}
	printf("%s",in[i]);
	if((l-k)%2){
	    s=1-s;
	    for(j=0;j<(l-k)/2+s;j++)printf(" ");
	}else{
	    for(j=0;j<(l-k)/2;j++)printf(" ");
	}
	puts("*");
    }
    for(i=0;i<l+2;i++)printf("*");
    puts("");
}
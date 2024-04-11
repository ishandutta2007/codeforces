#include<stdio.h>
#include<string.h>
char in[10000];
int main(){
    int c=0,ans=0;
    while(gets(in)!=NULL){
	if(in[0]=='+')c++;
	else if(in[0]=='-')c--;
	else{
	    int i;
	    for(i=0;in[i]!=':';i++);
	    ans+=c*(strlen(in)-i-1);
	}
    }
    printf("%d\n",ans);
}
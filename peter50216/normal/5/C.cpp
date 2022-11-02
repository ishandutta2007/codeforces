#include<stdio.h>
char in[1001000];
int pre[2001000];
int main(){
    int i;
    int ma=0,mc=1;
    scanf("%s",in+1);
    int x=1000500;
    for(i=1;in[i];i++){
	if(in[i]=='('){
	    if(!pre[x])pre[x]=i;
	    x++;
	}else{
	    pre[x]=0;
	    x--;
	    if(pre[x]){
		if(i-pre[x]+1>ma){
		    ma=i-pre[x]+1;
		    mc=1;
		}else if(i-pre[x]+1==ma)mc++;
	    }
	}
    }
    printf("%d %d\n",ma,mc);
}
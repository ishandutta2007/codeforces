#include<stdio.h>
char in[1000];
int main(){
    scanf("%s",in);
    int i;
    for(i=1;in[i];i++)if(in[i]>='a'&&in[i]<='z')break;
    if(in[i]==0){
	for(i=0;in[i];i++){
	    if(in[i]>='a'&&in[i]<='z')in[i]+='A'-'a';
	    else in[i]+='a'-'A';
	}
    }
    puts(in);
}
#include<stdio.h>
char in[10][10];
int main(){
    int i,j;
    for(i=0;i<8;i++)scanf("%s",in[i]);
    bool f=0;
    for(i=0;i<8;i++)for(j=0;j<8;j++){
	if(in[i][j]=='W')f=1;
    }
    if(!f){
	puts("8");
	return 0;
    }
    int a=0;
    for(i=0;i<8;i++){
	for(j=0;j<8;j++)if(in[i][j]=='W')break;
	if(j==8)a++;
    }
    for(i=0;i<8;i++){
	for(j=0;j<8;j++)if(in[j][i]=='W')break;
	if(j==8)a++;
    }
    printf("%d\n",a);
}
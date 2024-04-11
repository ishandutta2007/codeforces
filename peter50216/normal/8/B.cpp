#include<stdio.h>
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char di[]="LURD";
int map[300][300];
char in[300];
int main(){
    scanf("%s",in);
    int x=150,y=150;
    int i,j,k;
    for(i=0;in[i];i++){
	int d;
	for(d=0;d<4;d++)if(di[d]==in[i])break;
	if(map[x][y]){
	    puts("BUG");
	    return 0;
	}
	map[x][y]=i+1;
	x+=dx[d];y+=dy[d];
    }
    if(map[x][y]){
	puts("BUG");
	return 0;
    }
    map[x][y]=i+1;
    for(i=0;i<300;i++)for(j=0;j<300;j++)if(map[i][j]){
	for(k=0;k<4;k++){
	    x=i+dx[k];y=j+dy[k];
	    if(x>=0&&x<300&&y>=0&&y<300&&map[x][y]&&map[x][y]!=map[i][j]-1&&map[x][y]!=map[i][j]+1){
		puts("BUG");
		return 0;
	    }
	}
    }
    puts("OK");
}
#include <stdio.h>
#define MN 100000
int n,q,count;
bool b[4][MN+5];
int main(){
	scanf("%d%d",&n,&q);
	for(int r,c;q--;){
		scanf("%d%d",&r,&c);
		b[r][c] = !b[r][c];
		for(int dr=-1;dr<=1;dr++){
			for(int dc=-1;dc<=1;dc++){
				if(dr==0) continue;
				if(b[r][c] && b[r+dr][c+dc]) count++;
				if((!b[r][c]) && b[r+dr][c+dc]) count--;
			}
		}
		puts(count==0?"YES":"NO");
	}
}
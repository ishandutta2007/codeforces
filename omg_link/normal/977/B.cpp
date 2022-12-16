#include <stdio.h>
#include <string.h>
#define MN 100
int n,ai,aj,MAX,cnt[26][26];
char s[MN+5];
int main(){
	memset(cnt,0,sizeof(cnt)); MAX=0;
	scanf("%d%s",&n,&s[1]);
	for(int i=1;i<=n-1;i++)
		cnt[s[i]-'A'][s[i+1]-'A']++;
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			if(cnt[i][j]>MAX){
				MAX=cnt[i][j];
				ai=i,aj=j;
			}
	printf("%c%c",ai+'A',aj+'A');
}
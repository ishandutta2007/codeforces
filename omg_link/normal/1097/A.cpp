#include <stdio.h>
char s1[3],s2[3];
int main(){
	scanf("%s",&s1[0]);
	for(int i=0;i<5;i++){
		scanf("%s",&s2[0]);
		if(s2[0]==s1[0]||s2[1]==s1[1])
			return 0*puts("YES");
	}
	puts("NO");
}
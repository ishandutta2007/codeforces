#include <stdio.h>

char str[20][20];
int R[20],C[20];
int r,c;

int main() {
	int i,j,ans = 0;
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++) {
		scanf("%s",str[i]);
		for(j=0;j<c;j++)
			if(str[i][j] == 'S')
				R[i] = C[j] = 1;
	}
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			if(!R[i] || !C[j])
				ans++;
	printf("%d\n",ans);
	return 0;
}
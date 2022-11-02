#include<stdio.h>
int in[1010];
int main(){
    int n,k;
    int i,j,q;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&in[i]);
    for(i=1;i<=n;i++){
	for(j=1;j<=n;j++)if(!in[j])break;
	printf("%d%c",j,i==n?'\n':' ');
	for(q=1;q<=j-k;q++)in[q]--;
	in[j]--;
    }
}
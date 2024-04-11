#include<stdio.h>
int to[111];
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
	int a;
	scanf("%d",&a);
	to[a]=i;
    }
    for(i=1;i<=n;i++)printf("%d%c",to[i],(i==n)?'\n':' ');
}
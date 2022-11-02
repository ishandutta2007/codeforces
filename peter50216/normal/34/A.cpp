#include<stdio.h>
int in[1000];
inline int abs(int a){return a>0?a:-a;}
int main(){
    int n,i,c=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&in[i]);
    int mi=1000000000;
    for(i=0;i<n;i++){
	int j=(i+1)%n;
	if(abs(in[i]-in[j])<mi){
	    mi=abs(in[i]-in[j]);
	    c=i;
	}
    }
    printf("%d %d\n",c+1,(c+1)%n+1);
}
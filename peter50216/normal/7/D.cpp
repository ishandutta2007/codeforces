#include<stdio.h>
#include<string.h>
const int p=311;
char in[5000100];
long long h[5000100],h2[5000100];
long long pow[5000100];
int d[5000100];
int n;
inline int isp(int x){
    return h[x]==h2[n]-h2[n-x]*pow[x];
}
int main(){
    int i;
    scanf("%s",in);
    n=strlen(in);
    h[0]=h2[0]=0;
    pow[0]=1;
    for(i=0;i<n;i++){
	pow[i+1]=pow[i]*p;
	h[i+1]=h[i]*p+in[i];
	h2[i+1]=h2[i]*p+in[n-1-i];
    }
    int x=0;
    for(i=1;i<=n;i++){
	if(isp(i))d[i]=d[i/2]+1;
	else d[i]=0;
	x+=d[i];
    }
    printf("%d\n",x);
}
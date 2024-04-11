#include<stdio.h>
#include<math.h>
#include<string.h>
int in[1010];
int main(){
    int n,m,h,i;
    scanf("%d%d%d",&n,&m,&h);
    int s=0;
    for(i=0;i<m;i++){
	scanf("%d",&in[i]);
	s+=in[i];
    }
    if(s<n){
	puts("-1.0");
	return 0;
    }
    h--;
    n--;
    in[h]--;
    s--;
    if(in[h]==0||n==0){
	puts("0.0");
	return 0;
    }
    if(s-in[h]<n){
	puts("1.0");
	return 0;
    }
    double ans=1;
    for(i=0;i<in[h];i++)ans*=((double)s-n-i)/(s-i);
    printf("%.10lf\n",1-ans);
}
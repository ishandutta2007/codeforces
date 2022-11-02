#include<stdio.h>
int x[100100],y[100100];
inline long long solve(int* a,long long n){
    long long ans=0;
    long long sum=0;
    for(int i=0;i<n;i++){
	ans+=(n-1)*a[i]*a[i];
	ans-=2*sum*a[i];
	sum+=a[i];
    }
    return ans;
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
    printf("%I64d\n",solve(x,n)+solve(y,n));
}
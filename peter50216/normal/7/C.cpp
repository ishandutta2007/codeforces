#include<stdio.h>
inline long long gcd(long long a,long long b){if(b)while((a%=b)&&(b%=a));return a+b;}
inline void f(long long a,long long b,long long &x,long long &y){
    if(a==0){
	x=0;y=1/b;
	return;
    }
    f(b-(b/a)*a,a,y,x);
    x-=y*(b/a);
}
int main(){
    long long a,b,c;
    scanf("%I64d%I64d%I64d",&a,&b,&c);
    long long k=gcd(a,b);
    if(c%k){
	puts("-1");
	return 0;
    }
    a/=k;b/=k;c/=k;
    long long x,y;
    f(a,b,x,y);
    printf("%I64d %I64d\n",-x*c,-y*c);
}
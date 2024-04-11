#include<stdio.h>
int n,m,a,b;
inline int solve(){
    a--;b--;
    int ra=a/m,rb=b/m;
    if(ra==rb)return 1;
    if(a%m==0){
	if(b==n-1||b%m==m-1)return 1;
	else return 2;
    }
    if(b==n-1||b%m==m-1)return 2;
    if(a%m==(b%m)+1)return 2;
    if(ra==rb-1)return 2;
    return 3;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    printf("%d\n",solve());
}
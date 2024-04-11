#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n,k,l,c,d,p,nl,np;
    scanf("%d%d%d%d%d%d%d%d",&n,&k,&l,&c,&d,&p,&nl,&np);
    k*=l;c*=d;
    printf("%d\n",min(min(c,p/np),k/nl)/n);
}
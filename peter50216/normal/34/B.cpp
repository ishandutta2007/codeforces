#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10000];
int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    int s=0;
    for(i=0;i<m&&a[i]<0;i++)s-=a[i];
    printf("%d\n",s);
}
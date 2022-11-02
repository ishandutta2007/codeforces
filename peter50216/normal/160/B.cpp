#include<stdio.h>
#include<algorithm>
using namespace std;
char a[1000];
char b[1000];
int main(){
    int n,i,j;
    scanf("%d",&n);
    gets(a);
    for(i=0;i<n;i++)a[i]=getchar();
    for(i=0;i<n;i++)b[i]=getchar();
    sort(a,a+n);
    sort(b,b+n);
    for(i=0;i<n;i++)if(a[i]>=b[i])break;
    if(i==n){
        puts("YES");
        return 0;
    }
    for(i=0;i<n;i++)if(a[i]<=b[i])break;
    if(i==n){
        puts("YES");
        return 0;
    }
    puts("NO");
}
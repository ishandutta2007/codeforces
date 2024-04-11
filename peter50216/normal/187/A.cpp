#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int a[201000],b[201000];
int c[201000];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);

    }
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
        c[b[i]]=i;
    }
    for(i=1;i<=n;i++)a[i]=c[a[i]];
    a[0]=0;
    for(i=1;i<=n;i++)if(a[i]<a[i-1])break;
    printf("%d\n",n+1-i);
}
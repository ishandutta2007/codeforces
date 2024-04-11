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
long long in[101000];
int msb[101000];
int main(){
    int n,i,j;
    msb[1]=1;
    for(i=2;i<101000;i++)msb[i]=msb[i/2]<<1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%I64d",&in[i]);
    long long ans=0;
    for(i=1;i<n;i++){
        ans+=in[i];
        in[i+msb[n-i]]+=in[i];
        printf("%I64d\n",ans);
    }
}
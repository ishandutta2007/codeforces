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
char in[30010][22];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",&in[i]);
    for(j=0;in[0][j];j++){
        for(i=1;i<n;i++)if(in[i][j]!=in[0][j])break;
        if(i<n)break;
    }
    printf("%d\n",j);
}
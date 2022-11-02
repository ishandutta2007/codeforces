#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    int a=0;
    while((x+a)*100<n*y)a++;
    printf("%d\n",a);
}
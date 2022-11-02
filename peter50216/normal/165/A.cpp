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
int x[310],y[310];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
    int tmt=0;
    for(i=0;i<n;i++){
        int c=0;
        for(j=0;j<n;j++){
            if(x[j]<x[i]&&y[j]==y[i])c|=1;
            if(x[j]>x[i]&&y[j]==y[i])c|=2;
            if(x[j]==x[i]&&y[j]<y[i])c|=4;
            if(x[j]==x[i]&&y[j]>y[i])c|=8;
        }
        if(c==15)tmt++;
    }
    printf("%d\n",tmt);
}
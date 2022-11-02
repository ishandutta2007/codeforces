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
char in[1010][20];
int x[1010];
pair<int,string> XD[1010];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s%d",in[i],&x[i]);
        for(j=0;j<i;j++){
            if(strcmp(in[i],in[j])==0){
                x[j]=max(x[j],x[i]);
                i--;n--;break;
            }
        }
    }
    for(i=0;i<n;i++){
        int k=0;
        for(j=0;j<n;j++)if(x[j]<=x[i])k++;
        XD[i].first=k;
        XD[i].second=in[i];
    }
    sort(XD,XD+n);
    printf("%d\n",n);
    for(i=0;i<n;i++){
        printf("%s ",XD[i].second.c_str());
        int k=XD[i].first;
        if(k*100<50*n)puts("noob");
        else if(k*100<80*n)puts("random");
        else if(k*100<90*n)puts("average");
        else if(k*100<99*n)puts("hardcore");
        else puts("pro");
    }
}
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
bool np[1010000];
int pr[1010000],pc;
int pp[1010000],ppc;
char tmp[100];
inline int rev(int a){
    sprintf(tmp,"%d",a);
    int i,j;
    for(i=0,j=strlen(tmp)-1;i<j;i++,j--)swap(tmp[i],tmp[j]);
    return atoi(tmp);
}
int main(){
    long long i,j;
    for(i=2;i<=1000000;i++)if(!np[i]){
        pr[pc++]=i;
        for(j=i*i;j<=1000000;j+=i)np[j]=1;
    }
    for(i=0;i<pc;i++){
        int k=rev(pr[i]);
        if(pr[i]!=k&&np[k]==0)pp[ppc++]=pr[i];
    }
    int a;
    scanf("%d",&a);
    printf("%d\n",pp[a-1]);
}
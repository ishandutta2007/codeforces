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
bool np[10010000];
int pr[1001000],pc=0;
int mp[10010000];
int ad[10010000];
int main(){
    int i,j;
    ad[1]=1;
    for(i=2;i<=10000000;i++){
        if(!np[i]){
            pr[pc++]=i;
            mp[i]=i;
        }
        for(j=0;j<pc&&i*pr[j]<=10000000;j++){
            mp[i*pr[j]]=pr[j];
            np[i*pr[j]]=1;
            if(i%pr[j]==0)break;
        }
    }
    for(i=2;i<=10000000;i++){
        int ii=i/mp[i];
        if(ii%mp[i])ad[i]=ad[ii];
        else ad[i]=ad[ii/mp[i]]*mp[i]*mp[i];
    }
    int a,n;
    scanf("%d%d",&a,&n);
    long long s=0;
    for(i=a;i<a+n;i++)s+=i/ad[i];
    printf("%I64d\n",s);
}
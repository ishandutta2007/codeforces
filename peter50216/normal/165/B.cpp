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
    int n,k;
    scanf("%d%d",&n,&k);
    int l=1,r=n;
    while(l<r){
        int m=(l+r)/2;
        int mm=m;
        int cnt=0;
        while(mm){
            cnt+=mm;
            mm/=k;
        }
        if(cnt>=n)r=m;
        else l=m+1;
    }
    printf("%d\n",l);
}
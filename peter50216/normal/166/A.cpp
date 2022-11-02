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
pair<int,int> in[55];
int main(){
    int n,k,i;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        in[i]=make_pair(-a,b);
    }
    sort(in,in+n);
    int c=0;
    for(i=0;i<n;i++)if(in[i]==in[k-1])c++;
    printf("%d\n",c);
}
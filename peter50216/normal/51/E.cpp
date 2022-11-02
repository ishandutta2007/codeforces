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
int in[710][710];
long long ans;
int v[710];
int tw[710][710];
int a[710],b[710];
int od[710];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);a--;b--;
        in[a][b]=in[b][a]=1;
        od[a]++;od[b]++;
    }
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(!in[i][j])continue;
            for(k=0;k<n;k++)if(in[j][k])tw[i][k]++;
        }
    }
    for(i=0;i<n;i++)for(j=i+1;j<n;j++){
        if(!in[i][j])continue;
        for(k=0;k<n;k++){
            if(k==i||k==j)continue;
            ans+=(tw[i][k]-in[j][k])*(tw[j][k]-in[i][k]);
        }
        for(k=0;k<n;k++)if(in[i][k]&&in[j][k])ans-=od[k]-2;
    }
    printf("%I64d\n",ans/5);
}
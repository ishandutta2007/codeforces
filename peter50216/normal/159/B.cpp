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
int cnt[2][1010][1010];
int cc[2][1010];
int main(){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    while(n--){
        scanf("%d%d",&a,&b);
        cc[0][b]++;
        cnt[0][b][a]++;
    }
    while(m--){
        scanf("%d%d",&a,&b);
        cc[1][b]++;
        cnt[1][b][a]++;
    }
    int ans=0,a2=0,i,j;
    for(i=1;i<=1000;i++){
        ans+=min(cc[0][i],cc[1][i]);
        for(j=1;j<=1000;j++){
            a2+=min(cnt[0][i][j],cnt[1][i][j]);
        }
    }
    printf("%d %d\n",ans,a2);
}
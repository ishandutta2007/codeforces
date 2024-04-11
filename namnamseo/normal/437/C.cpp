#include <cstdio>
#include <algorithm>

int data[1010];
bool map[1010][1010];
int ec  [2010];
int maxind[1010];
bool dead[1010];

bool comp(const int a,const int b) { return data[a]>data[b]; }

int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i) scanf("%d",data+i);
    for(;m--;){
        scanf("%d%d",&i,&j);
        map[i][j]=map[j][i]=true;
        ++ec[i]; ++ec[j];
    }
    for(i=1;i<=n;++i) maxind[i]=i;
    std::sort(maxind+1,maxind+1+n,comp);
    long long sum=0;
    for(i=1;i<=n;++i){
        dead[maxind[i]]=true;
        for(j=1;j<=n;++j){
            if(!dead[j] && map[maxind[i]][j]){
                sum+=data[j];
            }
        }
    }
    printf("%I64d\n",sum);
    return 0;
}
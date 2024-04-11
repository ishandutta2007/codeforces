#include <cstdio>
#include <vector>

using namespace std;
vector<int> lst[100010];
int n,k;

int main()
{
    scanf("%d%d",&n,&k);
    int i,sz,j,op=-1;
    for(i=0;i<k;++i){
        scanf("%d",&sz);
        for(;sz--;){
            scanf("%d",&j);
            lst[i].push_back(j);
            if(j==1) op=i;
        }
    }
    sz=lst[op].size();
    int os;
    for(i=1;i<sz;++i){
        if(lst[op][i]!=i+1) break;
    }
    os=i;
    int ans=n-os+(n-os+1)-k;
    printf("%d\n",ans);
    return 0;
}
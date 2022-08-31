# include <cstdio>
# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
# include <cctype>
# include <set>
# include <map>
# include <cmath>
# include <queue>
# include <string>

using namespace std;

int cnt[5],a;

int main()
{
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
        scanf("%d",&a),cnt[a]++;
    
    int ret=0;
    ret+=cnt[4];
    if(cnt[3]>=cnt[1])cnt[1]=0,ret+=cnt[3];
    else cnt[1]-=cnt[3],ret+=cnt[3];
    ret+=cnt[2]>>1;
    if(cnt[2]&1)cnt[1]+=2;
    ret+=(cnt[1]+3)>>2;
    
    printf("%d\n",ret);
    return 0;
}
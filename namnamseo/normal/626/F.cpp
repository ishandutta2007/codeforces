#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;

int can [202][202][1001];
int data[201];

int M=int(1e9)+7;

inline void add(int& a,int b){
    a=(a+b)%M;
}

int main()
{
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;++i) scanf("%d",data+i);
    sort(data+1,data+n+1);
    int j,imb;
    can[1][0][0]=1;
    can[1][1][0]=1;
    for(i=1;i<n;++i){
        for(int grp=0; grp<=n; ++grp){
            int newimb = grp * (data[i+1]-data[i]);
            for(imb=0; imb+newimb<=k; ++imb){
                add(can[i+1][grp][imb+newimb], can[i][grp][imb]*1LL*(grp+1)%M);
                add(can[i+1][grp+1][imb+newimb], can[i][grp][imb]);
                if(grp)
                    add(can[i+1][grp-1][imb+newimb], grp*1LL*can[i][grp][imb]%M);
            }
        }
    }
    int ans=0;
    for(imb=0;imb<=k;++imb){
        add(ans, can[n][0][imb]);
    }
    printf("%d\n",ans);
    return 0;
}
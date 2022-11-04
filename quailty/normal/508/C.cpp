#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int w[305],e[305];
int main()
{
    int m,t,r;
    scanf("%d%d%d",&m,&t,&r);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    if(t<r)printf("-1");
    else{
        int ans=r;
        sort(w+1,w+m+1);
        for(int i=1;i<=r;i++){
            e[i]=w[1]+t+1-i;
        }
        for(int i=2;i<=m;i++){
            int cnt=0;
            for(int j=r;j>=1;j--){
                if(e[j]<=w[i]){
                    e[j]=w[i]+t-cnt;
                    cnt++;
                    ans++;
                }
            }
        }
        printf("%d",ans);
    }
    return 0;
}
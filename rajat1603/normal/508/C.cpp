#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    int x;
    scanf("%d",&x);
    return x;
}
#define pb push_back
#define mp make_pair
int main(){
    int n=scan(),t=scan(),r=scan();
    bool candle[1001]={0};
    bool ghost[1001]={0};
    for(int i=0;i<n;i++){
        int temp=scan();
        ghost[temp+300]=1;
    }
    int cur=0;
    int ans=0;
    for(int i=300;i<=600;i++){
        if(ghost[i]){
            int req=r-cur;
            for(int j=i-1;j>=i-t;j--){
                if(req==0)break;
                if(!candle[j]){
                    req--;
                    cur++;
                    candle[j]=1;
                    ans++;
                }
            }
            if(req>0){
                printf("-1");
                return 0;
            }
        }
        if(candle[i-t]==1){
            cur--;
        }
    }
    printf("%d",ans);
}
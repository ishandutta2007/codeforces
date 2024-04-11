#include <bits/stdc++.h>
using namespace std;
#define sq(x) ((x)*(x))
#define double long double
#define eps 1e-3
char ch[100100];

int a[1010];
int b[1010];

main(){
    int x,d;
    int s =0 ;
    vector<long long> ans;
    scanf("%d%d",&x,&d);
    long long k  = 0;
    for(int i=0;i<31;i++)
        if(x & (1<<i)){
            
            for(int u=0;u<i;u++)
                ans.push_back(k);
            s++;
            k += d+2;            
            
        }
        
    while(s--){
        ans.push_back(k);
        k += d+2;
    }
        
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%I64d ",ans[i]+1);
}
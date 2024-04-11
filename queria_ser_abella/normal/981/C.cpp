#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100100
#define debug 

int dg[maxn];

main(){
    
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b), a--, b--;
        dg[a]++;
        dg[b]++;
    }
    for(int i=0;i<n;i++)
        debug("%d ",dg[i]);
        
        debug("\n");
        
    int n3 = 0, q3 = -1, n1 = 0;
    vector<int> q1;
    for(int i=0;i<n;i++){
        if(dg[i] > 2){
            n3++;
            q3 = i;
        }
        if(dg[i] == 1){
            n1++;
            debug("%d has deg 1\n",i+1);
            q1.push_back(i);
        }
    }
    
    if(n3 > 1){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    if(n3 == 0){
        printf("1 %d %d\n",q1[0]+1,q1[1]+1);
        return 0;
    }
    if(n3 == 1){
        printf("%d\n",(n1+1)/2);
        for(int i=0;i+1<n1;i+=2)
            printf("%d %d\n",q1[i]+1,q1[i+1]+1);
        if(n1&1)
            printf("%d %d\n",q1[n1-1]+1,q3+1);
        
    }
}
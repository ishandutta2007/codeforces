#include <bits/stdc++.h>
#define maxn 1001000
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pip pair<ll,pii>
#define debug 
#define ll long long

char ans[4][110];

main(){
    int n,k;
    scanf("%d%d",&n,&k);
    if(k > 2 * (n-2)){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    
    for(int i=0;i<4;i++)
        for(int j=0;j<n;j++)
            ans[i][j] = '.';
            
    if(k%2 == 0){
        for(int i=1;i<=k/2;i++)
            ans[1][i] = ans[2][i] = '#';
    }
    else {
        int mid = (n)/2;
        int u = min(k,n-2);
        int d = u/2;
        for(int i=mid-d;i<=mid+d;i++)
            ans[1][i] = '#';
        k -= u;
        int r = k/2;
        for(int i=1;i<=r;i++)
            ans[2][i] = ans[2][n-i-1] = '#';
    }
    
    for(int i=0;i<4;i++)
        printf("%s\n",ans[i]);
        
}
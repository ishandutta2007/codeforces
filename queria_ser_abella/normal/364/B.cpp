#include <bits/stdc++.h>
#define pii pair<int,int>
#define maxn 55
#define ll long long
#define debug
using namespace std;

int dp[10100*maxn];
int v[maxn];
int n;

int get(int x){
    int &r = dp[x];
    if(r+1)
        return r;
    if(x == 0 || x == v[0])
        return 0;
    for(int i=1;i<n;i++)
        if(x >= v[i] && get(x-v[i]) < i)
            return r = i;
    return r = n;
}

int main(){
    int d;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++)
        scanf("%d",v+i);
    memset(dp,-1,sizeof(dp));
    int val = 0, t = 0 ;
    while(1){
        int ok = 0;
        for(int i=val+d;i>val;i--)
            if(get(i) != n){
                ok = 1;
                val = i;
                t++;
                break;
            }
        if(!ok)
            break;
    }
    printf("%d %d\n",val,t);
}
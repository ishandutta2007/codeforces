#include <bits/stdc++.h>
#define maxn 500500
#define mod 1000000007
#define pb push_back
#define debug 
#define pii pair<int,int>
typedef long long ll;
using namespace std;

ll a[maxn];
int x[maxn];
int aux[maxn];
int sc[maxn];
int calc[maxn];

ll v[maxn];

void go(int n){
    
    for(int i=0;i<n;i++) calc[i] = -1, sc[i] = 0;
    
    int mx = -1;
    for(int i=0;i<n;i++){
        sc[x[i]]++;
        mx = max(mx,x[i]);
        if(mx > i)
            calc[i] = i+1;
        else
            calc[i] = i;
    }
    
    for(int i=0;i<n;i++)
        if(sc[i] == n)
            calc[i] = -1;
    
}

int main(){
    
    int n;
    ll t;
    set<int> S;
    scanf("%d%lld",&n,&t);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i);
    for(int i=0;i<n;i++){
        scanf("%d",x+i);
        x[i]--;
        
        if(i && x[i] < x[i-1]){
            printf("No\n"); exit(0);
        }
        S.insert(x[i]);
    }
    
    if(S.size() == 1){
        if(n == 1){
            printf("Yes\n%lld\n",a[0]+t); exit(0);
        }
        if(x[0] < n-1){
            printf("No\n"); exit(0);
        }
        printf("Yes\n");
        for(int i=0;i<n;i++)
            printf("%lld ",a[n-1]+t+1+i);
        exit(0);
       // printf("No\n");exit(0);
    }
    
    go(n);
    for(int i=0;i<n;i++){
        debug("%d -> %d\n",i,calc[i]);
        if(calc[i] == -1){
            if(i == 0) v[i] = 0;
            else v[i] = v[i-1];
        }
        else v[i] = a[calc[i]] + t;
        if(i && v[i] == v[i-1])
            v[i]++;
    }
    
    for(int i=0;i<n;i++)
        debug("%lld ",v[i]);
    debug("\n");
    
    for(int i=0;i<n;i++)
        x[i] = min(x[i]+1,n-1);
        
    go(n);
    
    for(int i=0;i<n;i++)
        debug("%d -> %d\n",i,calc[i]);
    
    int bads = 0;
    for(int i=0;i<n;i++)
        if(calc[i]+1)
            if(v[i] < a[calc[i]] + t){
                bads = 1;
            }
    if(!bads){
        printf("No\n");
        exit(0);
    }
    printf("Yes\n");
    
    for(int i=0;i<n;i++)
        printf("%lld ",v[i]);

}
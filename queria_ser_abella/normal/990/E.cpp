#include <bits/stdc++.h>
#define ll long long
#define maxn 3003000
#define pii pair<int,int>
#define pb push_back
#define left ifushf
using namespace std;

int bl[maxn];
int left[maxn];

int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a;
        scanf("%d",&a);
        bl[a] = 1;
    }
    
    if(bl[0]){
        printf("-1\n");
        return 0;
    }
    left[0] = 0;
    for(int i=1;i<=n;i++){
        if(bl[i])
            left[i] = left[i-1];
        else left[i] = i;
    }
    
    ll ans = (1ll<<60);
    
    for(int i=1;i<=k;i++){
        int val;
        scanf("%d",&val);
        int t = 0;
        int pos = 0;
        while(pos < n){
            t++;
            pos += i;
            if(pos >= n) break;
            if(left[pos] <= pos-i) break;
            pos = left[pos];
        }
        if(pos >= n)
            ans = min(ans,(ll)val*t);
    }
    if(ans != (1ll<<60))
        printf("%lld\n",ans);
    else
        printf("-1\n");
    
}
#include <bits/stdc++.h>
#define maxn 2020
#define pb push_back
#define debug
typedef long long ll;
using namespace std;

int main(){
    int nt;
    scanf("%d",&nt);
    while(nt--){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        if(a > b+1){
            printf("NO\n");
            continue;
        }
        a += b;
        int pr = 1;
        for(ll i=2;i*i<=a;i++)
            if(a%i == 0)
                pr = 0;
        if(pr)
            printf("YES\n");
        else
            printf("NO\n");
            
            
    }
}
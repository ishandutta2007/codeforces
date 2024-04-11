#include <bits/stdc++.h>
#define ll long long
#define maxn 300300
using namespace std;

int qnt[100];

int main(){
    
    ll n;
    scanf("%lld",&n);
    
    for(int i=0;i<50;i++)
        qnt[i] = 1e9;

    for(int n4=0;n4<9;n4++)
        for(int n9=0;n9<49;n9++){
            if(n4+n9 > n) continue;
            int x = 4*n4 + 9*n9;
            x %= 49;
            qnt[x] = min(qnt[x],n4+n9);
        }
    
    ll ans = 0;
    for(int i=0;i<49;i++){
        if(qnt[i] > 1e8) continue;
        ans += n - qnt[i] + 1;
    }
    printf("%lld\n",ans);
}
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll t[100100], x[100100], xco[100100];

int main(){
    int z;
    scanf("%d", &z);
    while(z--){
        ll n;
        scanf("%lld", &n);
        ll t0=0, t1=0, x0=0, x1=0, di;
        for (int i=0;i<n;i++) scanf("%lld %lld", t+i, x+i);
        for (int i=0;i<n;i++){
            if (t1<=t[i]){
                xco[i]=x0;
                t0=t[i];
                t1=abs(x0-x[i])+t[i];
                x0=x[i];
                x1=xco[i];
                if (x0<=xco[i]) di=-1;
                else di=1;
            }
            else{
                xco[i]=x1+di*(t[i]-t0);
            }
            //printf("%lld ", xco[i]);
        }
        xco[n]=x0;
        //printf("\n");
        ll ans=0;
        for (int i=0;i<n;i++){
            if (abs(xco[i+1]-xco[i])==abs(xco[i+1]-x[i])+abs(xco[i]-x[i])) ans++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
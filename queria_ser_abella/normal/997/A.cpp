#include <bits/stdc++.h>
#define ll long long
#define maxn 300300
using namespace std;

char str[maxn];

int main(){
    
    ll n,a,b;
    scanf("%lld%lld%lld",&n,&a,&b);
    scanf(" %s",str);
    int c0 = 0;
    if(str[0] == '0') c0++;
    for(int i=1;i<n;i++)
        if(str[i] == '0' && str[i-1] == '1') c0++;
    if(c0 == 0){
        printf("0\n");
    }
    else if(a < b){
        printf("%lld\n",b + a * (c0-1) );
    }  
    else 
        printf("%lld\n",b * c0);
}
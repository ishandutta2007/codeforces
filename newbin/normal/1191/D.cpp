#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;
ll n;
ll a[maxn];
int main()
{
    cin>>n;
    for(int i = 1; i <= n; ++i){
        scanf("%I64d", &a[i]);
    }
    a[0] = -1;
    if(n == 1){
        if(a[1]&1){
            printf("sjfnb\n");
        }
        else printf("cslnb\n");
        return 0;
    }
    sort(a,a+n+1);
    int id = -1;
    int cnt = 0;
    for(int i = n-1;i >= 0; --i){
        if(a[i] == a[i+1]){
            cnt++; id = i;
        }
    }
    if(cnt > 1) printf("cslnb\n");
    else if(cnt == 1 && a[id] == 0) printf("cslnb\n");
    else if(cnt == 1 && a[id-1] == a[id] - 1) printf("cslnb\n");
    else{
        ll p = 0;
        if(cnt == 1) a[id]--, p++;
        for(int i = 1; i <= n; ++i){
            if(a[i] - a[i-1] > 1){
                p += (a[i] - a[i-1] -1)*(n+1-i);
                p %= 2;
            }
        }
        p %= 2;
        if( p == 0) printf("cslnb\n");
        else printf("sjfnb\n");
    }
}
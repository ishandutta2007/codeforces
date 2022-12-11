#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;
ll n, m, k;
ll a[maxn];
int main()
{
    cin>>n>>m>>k;
    ll pos = 0;
    ll res = 0;
    int ans = 0;
    for(int i = 1; i <= m; ++i){
        scanf("%I64d", &a[i]);
    }
    int i = 1;
    while(i <= m){
        ans ++;
        if(pos < a[i]) pos =pos + (a[i] - pos)/k *k;
        while(pos < a[i]) pos += k;
        for(i; i <= m && a[i] <= pos; ++i){
            res++;
        }
        pos += res;
        //cout<<pos<<endl;
        res = 0;
    }
    cout<<ans<<endl;
}
/*
11 3 5
5 7 11
*/
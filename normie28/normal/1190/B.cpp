#include <bits/stdc++.h>
#define ft first
#define sd second
#define ll long long
#define pb push_back
using namespace std;
 
const int maxn = 1e5 + 3;
ll n;
ll v[maxn];
ll sum = 0;
map <ll, ll> freq;
 
int main()
{
    scanf("%lld",&n);
    sum = (n * (n - 1))/2;
    sum %= 2;
    for( ll i = 1; i <= n; i++ ){
        scanf("%lld", &v[i]);
        sum = (sum + v[i])%2;
        freq[v[i]]++;
    }
    ll g1 = 0;
    for( auto x : freq ){
        if( x.sd == 2 ){
            g1++;
            if(g1 == 1 && freq.find(x.ft - 1) != freq.end() || x.ft == 0)
                 return printf("cslnb"), 0;
        }
        if(g1 == 2 || x.sd > 2 )
            return printf("cslnb"), 0;
    }
 
    printf( sum&1 ? "sjfnb" : "cslnb" );
}
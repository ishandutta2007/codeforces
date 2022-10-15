#include <bits/stdc++.h>
 
using namespace std;
 
#define MAXN 500005
typedef long long ll;
string s;
ll r[MAXN], l[MAXN];
ll n, a,b, T;
 
int main()
{
    cin >> n >> a >> b >> T >> s;
    int ls = 0;
    r[0] = 1 + (s[0]=='w')*b;
 
    for(int i=1; i<n; ++i){
        r[i] = 1 + r[i-1] + a + (s[i]=='w')*b;
    }
    for(int i=n-1; i>0; --i){
        l[i] = 1 + l[(i+1)%n] + a + (s[i]=='w')*b;
    }
    ll ans = 0;
    ll j = 1;
    for(ll i=0; i<n; ++i){
        ll tmp = T - r[i];
        if(tmp >= 0){
            ans = max(ans, i+1);
            tmp -= a * i;
            if(tmp > 0){
                while(tmp < l[j] && j<n) ++j;
                ans = max(ans, i+1+n-max(j,i+1));
            }
        } else break;
    }
    j = n-1;
    for(ll i=n-1; i>=1; --i){
        ll tmp = T - l[i] - r[0];
        if(tmp >= 0){
            ans = max(ans, n-i+1);
            tmp -= a * (n-i) - 1 - b*(s[0]=='w');
            if(tmp > 0){
                while(tmp < r[j] && j>0) --j;
                ans = max(ans, n-i+min(i-1LL, j)+1);
            }
        } else break;
    }
    cout << ans;
}

#include <cstdio>
#include <iostream>
#define maxn 1000000
typedef long long ll;
using namespace std;

ll MAX(ll a, ll b) {return a>b?a:b;}
ll MIN(ll a, ll b) {return a<b?a:b;}
ll a[maxn], h1[maxn], h2[maxn], cost1[maxn], cost2[maxn];
ll sum1[maxn], sum2[maxn];
int main(){
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        // scanf("%d", &a[i]);
        cin >> a[i];
    }

    for (int i=1; i<=n; i++) {
        h1[i] = MAX(a[i], h1[i-1]+1);
        cost1[i] = h1[i] - a[i];
        sum1[i] = sum1[i-1] + cost1[i];
    }
    for (int i=n; i>=1; i--) {
        h2[i] = MAX(a[i], h2[i+1]+1);
        cost2[i] = h2[i] - a[i];
        sum2[i] = sum2[i+1] + cost2[i];
    }

    ll ans = 10000000000000000;
    for (int i=1; i<=n; i++) {
        ans = MIN(ans, sum1[i-1]+sum2[i+1]+MAX(h1[i], h2[i])-a[i]);
    }

    cout << ans << endl;
    return 0;
}
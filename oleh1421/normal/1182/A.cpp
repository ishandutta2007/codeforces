#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int cnt[15000001];
int a[3000001];
char used[15000001];
int main()
{
    ll n;cin>>n;
    if (n%2) cout<<0;
    else cout<<(1ll<<(n/2ll));
    return 0;
}
//1-0
//3-1
//5-2
//7 3
//9 4
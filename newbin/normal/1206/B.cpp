#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int main()
{
    int r = 1;
    int n;
    ll ans = 0;
    int z = 0;
    cin>>n;
    while(n--){
        ll x;
        scanf("%I64d", &x);
        if(x == 0) z = 1, ans++;
        else if(x > 0) ans += x-1;
        else ans += (-1-x), r*=-1;
    }
    if(r == -1 && z == 0) ans += 2;
    cout<<ans<<endl;
}
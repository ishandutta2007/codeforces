#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll r, g, b, ans=0;
    cin >> r >> g >> b;
    if(r<g) swap(r, g);
    if(g<b) swap(g, b);
    if(r<g) swap(r, g);
    ll tmp = min(r-g, g-b);
    r-=2*tmp;
    g-=tmp;
    ans += tmp;
    if(g){
        if(g == b){
            ll df=r-g;
            ll tmp = min(df/3, g);
            r -= 4*tmp;
            g -= tmp;
            b -= tmp;
            ans += 2*tmp;
            if(r == g){
                ans += r;
            } else if(r == g+1){
                ans += g;
            } else if(r == g+2){
                ans += g;
            }
        } else {
            ll df=g-b;
            ll tmp=df/3;
            ans += 2*tmp;
            r -= 3*tmp; g -= 3*tmp;
            if(g == b){
                ans += g;
            } else if(g == b+1){
                ans += b;
            } else if(g == b+2){
                ans += b + 1;
            }
        }
    }
    cout << ans;
    return 0;
}
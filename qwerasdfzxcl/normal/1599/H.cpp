#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int query(ll x, ll y){
    if(x>1000000000 || y>1000000000) return 1e9+1;
    printf("? %lld %lld\n", x, y);
    fflush(stdout);
    ll ret;
    scanf("%lld", &ret);
    return ret;
}

ll x, y, p, q;

int main(){
    x = y = 1;
    ll dist = query(x, y);
    while(dist > 1){
        ll ret = query(x+dist/2, y);
        if(dist - ret != dist/2) y += dist/2;
        else x += dist/2;
        dist -= dist/2;
    }
    if(query(1, y+1) == x-1) y++;
    else x++;

    ll tmp = query(1000000000, 1);
    p = 1000000000 - (tmp - (y - 1));
    tmp = query(1, 1000000000);
    q = 1000000000 - (tmp - (x - 1));

    printf("! %lld %lld %lld %lld\n", x, y, p, q);
    fflush(stdout);
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, l, v1, v2, k, num;
    cin >> n >> l >> v1 >> v2 >> k;

    long double d, h, t, ride, wait, all, wwait;
    d = (l + 0.0)/v2;
    h = (l + 0.0)/v1;

    for(int i = 0; i<50; i++){
        t = (d + h)/2;
        ride = (t*v1*v2 - l*v2)/(v1 - v2);
        num = ceil((n + 0.0)/ k);

        wait = (ride * (v2 - v1))/v2;
        wwait = (wait * v2)/(v2 + v1);
        all = num * ride - (num - 1) * wwait;
        if(all > l) d = t;
        else h = t;
    }

    cout << setprecision(10) << t;

}
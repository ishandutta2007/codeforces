#include <bits/stdc++.h>
#define ll long long


using namespace std;

inline int gcd(int a, int b) {
    int r = a % b;
    while(b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


inline bool check(int a, int b) {
    int nr = gcd(a, b);
    ll x = (1LL * a * b) / nr;
    return (1LL * nr * nr) % x == 0;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    scanf("%d" ,&n);
    for(i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d" ,&a,&b);
        ll x = 1LL * a * b;
        int rez = 0;
        for(ll pas = 1 << 20; pas; pas >>= 1)
            if(1LL * (rez + pas) * (rez + pas) * (rez + pas) <= x)
                rez += pas;
        if(1LL * rez * rez * rez == x && check(a, b))
            puts("YES");
        else
            puts("NO");
       // printf("\n");
    }
    //cin.close();
    //cout.close();
    return 0;
}
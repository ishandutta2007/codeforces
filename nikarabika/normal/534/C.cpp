#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 2e5 + 10;
LL d[maxn];
LL n;
LL a, S;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a;
    for(int i = 0; i < n; i++){
        cin >> d[i];
        S += d[i];
    }
    for(int i = 0; i < n; i++){
        LL Max = a - n + 1,
            Min = a - S + d[i];
        LL x = d[i] - (min(d[i], Max) - max(1LL, Min) + 1);
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

bool prime(int n){
    if (n == 1) return 1;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    int now = 2;
    map<int,int> used;
    while(now < 1e15){
        used[now] = 1;
        now *= 4;
    }
    while(t--){
        int n;
        cin >> n;
        if (used[n]){
            cout << "Bob" << endl;
            continue;
        }
        cout << (n % 2 == 0 ? "Alice" : "Bob") << endl;
    }
    return 0;
}
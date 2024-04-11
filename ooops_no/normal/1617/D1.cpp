#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define ld long double

mt19937 rnd(51);

int ask(int a, int b, int c){
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    int p;
    cin >> p;
    return p;
}

signed main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int last = ask(1, 2, 3), bad = 0, good = 0;
        for (int i = 2; i <= n; i++){
            int a = i, b = i + 1, c = i + 2;
            if (b > n) b -= n;
            if (c > n) c -= n;
            int val = ask(a, b, c);
            if (val != last){
                if (last == 0){
                    bad = i - 1, good = c;
                }
                else{
                    good = i - 1, bad = c;
                }
                break;
            }
        }
        vector<int> arr{bad};
        for (int i = 1; i <= n; i++){
            if (bad == i || good == i) continue;
            if (ask(bad, good, i) == 0){
                arr.pb(i);
            }
        }
        cout << "! " << arr.size() << ' ';
        for (auto to : arr){
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}
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
        int n, bad = 0, good = 0;
        cin >> n;
        vector<int> type(n + 1);
        for (int i = 1; i <= n; i += 3){
            type[i] = ask(i, i + 1, i + 2);
        }
        for (int i = 1; i <= n; i += 3){
            if (type[i] != type[i + 3]){
                type[i + 1] = ask(i + 1, i + 2, i + 3), type[i + 2] = ask(i + 2, i + 3, i + 4);
                for (int j = i; j < i + 3; j++){
                    if (type[j] != type[j + 1]){
                        if (type[j] == 0){
                            bad = j, good = j + 3;
                        }
                        else{
                            bad = j + 3, good = j;
                        }
                    }
                }
                break;
            }
        }
        vector<int> arr{bad};
        for (int i = 1; i <= n; i += 3){
            if ((i - 1) / 3 == (bad - 1) / 3 || (i - 1) / 3 == (good - 1) / 3){
                for (int j = i; j < i + 3; j++){
                    if (bad == j || good == j){
                        continue;
                    }
                    if (ask(good, bad, j) == 0){
                        arr.pb(j);
                    }
                }
            }
            else if (type[i] == 0){
                if (ask(i, i + 1, good) == 0){
                    arr.pb(i);
                    arr.pb(i + 1);
                    if (ask(i + 2, good, bad) == 0) arr.pb(i + 2);
                }
                else{
                    arr.pb(i + 2);
                    if (ask(i, good, bad) == 0) arr.pb(i);
                    else arr.pb(i + 1);
                }
            }
            else{
                if (ask(i, i + 1, bad) == 1){
                    if (ask(i + 2, good, bad) == 0) arr.pb(i + 2);
                }
                else{
                    if (ask(i, good, bad) == 0) arr.pb(i);
                    else arr.pb(i + 1);
                }
            }
        }
        cout << "! " << arr.size() << ' ';
        for (auto to : arr) cout << to << ' ';
        cout << endl;
    }
    return 0;
}
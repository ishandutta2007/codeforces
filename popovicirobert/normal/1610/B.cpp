#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";


using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int l = 0, r = n - 1;
        while (l < r && arr[l] == arr[r]) {
            l++, r--;
        }

        auto Check = [&](int x) -> bool {
            vector<int> new_arr;
            for (auto itr : arr) {
                if (itr != x) {
                    new_arr.push_back(itr);
                }
            }
            auto temp = new_arr;
            reverse(temp.begin(), temp.end());
            return temp == new_arr;
        };

        if (l >= r) {
            cout << "YES\n";
        } else {
            if (Check(arr[l]) || Check(arr[r])) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    

   
    return 0;
}
#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int maxn = 1e4 + 5;
int a[maxn];
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        memset(a, -1, sizeof(a));
        for(int i = 1; i <= n; i++) {
            if(a[i] >= 0) continue;
            vector<int> vec;
            int x = i;
            while(true) {
                cout << "? " << i << endl;
                cin >> x;
                if(!vec.empty() && vec[0] == x) break;
                vec.push_back(x);
            }
            vec.push_back(vec[0]);
            for(int i = 1; i < vec.size(); i++) a[vec[i-1]] = vec[i];
        }
        cout << "!";
        for(int i = 1; i <= n; i++) cout << " " << a[i];
        cout << endl;
    }
    return 0;
}
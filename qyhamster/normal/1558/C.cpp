#include <bits/stdc++.h>
using namespace std;
int a[4000], n;
void op(int x) {
    for(int i = 1; i <= x/2; i++) swap(a[i], a[x-i+1]);
}
int fnd(int x) {
    for(int i = 1; i <= n; i++) if(a[i] == x) return i;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        vector<int> res;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        bool check = 1;
        for(int i = 1; i <= n; i++) {
            if((a[i]+i) % 2) check = 0;
        }
        if(!check) {
            cout << -1 << endl;
            continue;
        }
        for(int i = n; i > 2; i -= 2) {
            int idx = fnd(i);
            op(idx);
            res.push_back(idx);

            idx = fnd(i-1);
            op(idx-1);
            res.push_back(idx-1);

            op(i);
            res.push_back(i);

            idx = fnd(i);
            op(idx);
            res.push_back(idx);

            op(i);
            res.push_back(i);
        }
        //for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
        cout << res.size() << endl;
        for(auto k: res) cout << k << " "; cout << endl;
    }
    return 0;
}
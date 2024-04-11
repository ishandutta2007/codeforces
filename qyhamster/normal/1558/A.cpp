#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        set<int> s;
        int x = (a+b)/2;
        int f = (a+b)%2;
        for(int i = 0; i <= a; i++) {
            s.insert(i+(b-x+i));
            s.insert(i+(b-x+i-f));
        }
        cout << s.size() << '\n';
        for(auto x: s) cout << x << " "; cout << '\n';
    }
    return 0;
}
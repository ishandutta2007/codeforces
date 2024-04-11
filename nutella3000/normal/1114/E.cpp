#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int gcd(int a,int b) {
    if (a == 0) return b;
    return gcd(b % a,a);
}
int rnd(int i) {
    return i * 123124 + 1348 - i * 134 / 13456 + 2344 * i * i * i * i * i * 123;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a;
    if (n <= 60) {
        for(int i = 1;i <= n;i++) {
            cout << "? " << i << '\n';
            cout.flush();
            int u;
            cin >> u;
            a.push_back(u);
        }
        sort(a.begin(),a.end());
        cout << "! " << a[0] << " " << a[1] - a[0] << '\n';
    }else{
        int l = -1;
        int r = 1000000001;
        while(l != r - 1) {
            int m = (l + r) / 2;
            cout << "> " << m << '\n';
            cout.flush();
            bool u;
            cin >> u;
            if (u) l = m;
            else r = m;
        }
        a.push_back(r);
        for(int i = 0;i < 28;i++) {
            int u = 0;
            u = (rnd(i) % n + n) % n;
            cout << "? " << u + 1 << '\n';
            cout.flush();
            int y;
            cin >> y;
            a.push_back(y);
        }
        sort(a.begin(),a.end());
        int gc = 0;
        for(int i = 0;i < a.size() - 1;i++) {
            gc = gcd(min(gc,a[i + 1] - a[i]),max(a[i + 1] - a[i],gc));
        }
        cout << "! " << a[a.size() - 1] - (n - 1) * gc << " " << gc << '\n';//
    }
}
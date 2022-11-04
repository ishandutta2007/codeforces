#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, k;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    int x = n, y = m, aux = k;
    int d = 2;
    while(d * d <= k) {
        while(k % d == 0) {
            if(n % d == 0) {
                n /= d;
                aux /= d;
            }
            else if(m % d == 0) {
                m /= d;
                aux /= d;
            }
            k /= d;
        }
        d++;
    }
    if(k > 1) {
        if(n % k == 0) {
            n /= k;
            aux /= k;
            k = 1;
        }
        else if(m % k == 0) {
            m /= k;
            aux /= k;
            k = 1;
        }
    }
    k = aux;
    if(k > 2) {
        cout << "NO";
        return 0;
    }
    if(k == 2) {
        cout << "YES" << "\n";
        cout << 0 << " " << 0 << "\n" << n << " " << 0 << "\n" << 0 << " " << m;
    }
    else {
        if(2 * n <= x) {
            cout << "YES" << "\n";
            cout << 0 << " " << 0 << "\n" << 2 * n << " " << 0 << "\n" << 0 << " " << m;
        }
        else if(2 * m <= y) {
            cout << "YES" << "\n";
            cout << 0 << " " << 0 << "\n" << n << " " << 0 << "\n" << 0 << " " << 2 * m;
        }
        else {
            cout << "NO";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}
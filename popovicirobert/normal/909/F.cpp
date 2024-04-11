#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

int sol[MAXN + 1];


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    if(n & 1) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        int aux = n;
        while(aux > 0) {
            int p2 = 0;
            while((1 << p2) <= aux) {
                p2++;
            }
            p2--;
            int a = (1 << p2) - 1;
            int b = (1 << p2);
            while(b <= aux) {
                sol[b] = a;
                sol[a] = b;
                a--;
                b++;
            }
            aux = a;
        }
        for(i = 1; i <= n; i++) {
            cout << sol[i] << " ";
        }
        cout << endl;
    }
    if(n <= 5 || (n & (n - 1)) == 0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        if(n == 6) {
            cout << "3 6 2 5 1 4";
        }
        else {
            cout << "7 3 6 5 1 2 4 ";
            int a = 8;
            while(a <= n) {
                int b = min(2 * a - 1, n);
                for(i = a; i < b; i++) {
                    cout << i + 1 << " ";
                }
                cout << a << " ";
                a = b + 1;
            }
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}
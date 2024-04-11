#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int x = 0, y = 0, d = n / 2, c = n - d;
    if (n > a * b){
        cout << -1;
        return 0;
    }
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            if (i % 2 == j % 2)
                if (x == c)
                    cout << 0;
                else
                    cout << 2 * x + 1, x++;
            else
                if (y == d)
                    cout << 0;
                else
                    cout << 2 * y + 2, y++;
            cout << ' ';
        }
        cout << '\n';
    }
}
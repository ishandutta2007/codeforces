#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

vector <int> sol;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin >> n;
    if(n % 4 == 0) {
        cout << 0 << endl;
        cout << n / 2 << " ";
        for(i = 1; i <= n - i + 1; i += 2) {
            cout << i << " " << n - i + 1 << " ";
        }
    }
    else {
        if(n % 4 == 3) {
            for(i = 2; i < (n + 1) / 2; i += 2) {
                sol.push_back(i);
            }
            for(i = n; i > (n + 1) / 2; i -= 2) {
                sol.push_back(i);
            }
            cout << 0 << endl;
            cout << sol.size() << " ";
            for(auto it : sol)
                cout << it << " ";
        }
        else if(n % 4 == 1) {
            for(i = 2; i < (n + 1) / 2; i += 2) {
                sol.push_back(i);
            }
            for(i = n; i > (n + 1) / 2; i -= 2) {
                sol.push_back(i);
            }
            cout << 1 << endl;
            cout << sol.size() << " ";
            for(auto it : sol)
                cout << it << " ";
        }
        else {
            cout << 1 << endl;
            cout << n / 2 << " ";
            int i = 1;
            while(i <= n) {
                cout << i << " ";
                if(i % 2 == 1)
                    i += 3;
                else
                    i++;
            }
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}
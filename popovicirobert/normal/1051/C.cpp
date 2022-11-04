#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

int fr[101], arr[101];
char sol[101];

int main() {
    //ifstream cin("C.in");
    //ofstream cout("C.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        arr[i] = x;
        fr[x]++;
    }
    int nr0 = 0, nr1 = 0;
    for(i = 1; i <= n; i++) {
        if(fr[arr[i]] == 1) {
            if(nr0 < nr1) {
                sol[i] = 'A';
                nr0++;
            }
            else {
                sol[i] = 'B';
                nr1++;
            }
        }
        else if(fr[arr[i]] == 2) {
            sol[i] = 'A';
        }
    }
    if(nr0 != nr1) {
        for(i = 1; i <= n; i++) {
            if(fr[arr[i]] == 0) {
                continue;
            }
            if(fr[arr[i]] > 2) {
                char ch;
                if(nr0 < nr1) {
                    nr0++;
                    sol[i] = 'A';
                    ch = 'B';
                }
                else {
                    nr1++;
                    sol[i] = 'B';
                    ch = 'A';
                }
                for(int j = i + 1; j <= n; j++) {
                    if(arr[i] == arr[j]) {
                        sol[j] = ch;
                    }
                }
                fr[arr[i]] = 0;
                break;
            }
        }
    }
    for(i = 1; i <= n; i++) {
        if(sol[i] != 'A' && sol[i] != 'B') {
            sol[i] = 'A';
        }
    }
    if(nr1 != nr0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    for(i = 1; i <= n; i++) {
        cout << sol[i];
    }
    //cin.close();
    //cout.close();
    return 0;
}
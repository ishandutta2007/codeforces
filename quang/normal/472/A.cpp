#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 1000100;

int n;
bool E[N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    E[1] = 1;
    for(int i = 2; i <= n + 5; i++)
        if(!E[i])
            for(int j = i + i; j <= n + 5; j += i)
                E[j] = 1;
    for(int i = 2; i <= n / 2; i++) {
        if(E[i] && E[n - i]) {
            cout << i << " " << n - i;
            return 0;
        }
    }
    return 0;
}
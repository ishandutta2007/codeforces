#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 43

using namespace std;

int fr[100005];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        fr[x]++;
    }
    int ans = 0;
    for(i = 1; i <= (int) 1e5; i++) {
        ans |= (fr[i] % 2);
    }
    if(ans == 1)
        cout << "Conan";
    else
        cout << "Agasa";
    //cin.close();
    //cout.close();
    return 0;
}
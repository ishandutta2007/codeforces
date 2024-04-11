#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

int ask(int i, int j){
    i++, j++;
    cout << "SCAN " << i << " " << j << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

int dig(int i, int j){
    i++, j++;
    cout << "DIG " << i << " " << j << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

int n, m;

void solve(){
    cin >> n >> m;
    int s1 = ask(0, 0), s2 = ask(0, m - 1) - 2 * (m - 1);
    int as = (s1 + s2) / 2;
    int bs = (s1 - s2) / 2;

    int tmp;
    tmp = ask(as / 2, 0) - bs;
    int a1, a2;
    for (int i = 0; i < n; i++){
        int j = as - i;
        if (tmp == j - i){
            a1 = i, a2 = j;
            break;
        }
    }

    tmp = ask(0, bs / 2) - as;
    int b1, b2;
    for (int i = 0; i < m; i++){
        int j = bs - i;
        if (tmp == j - i){
            b1 = i, b2 = j;
            break;
        }
    }

    if (dig(a1, b1)){
        dig(a2, b2);
        return;
    }
    dig(a1, b2);
    dig(a2, b1);

}

int main(){
    //ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
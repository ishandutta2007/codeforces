#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define mod 1000000007
#define pi acos(-1)
using namespace std;

int n;
string s[1111];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i][0] == 'O' && s[i][1] == 'O') {
            s[i][0] = '+';
            s[i][1] = '+';
            flag = true;
            break;
        } else if (s[i][3] == 'O' && s[i][4] == 'O') {
            s[i][3] = '+';
            s[i][4] = '+';
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) cout << s[i] << endl;
    } else cout << "NO";
}
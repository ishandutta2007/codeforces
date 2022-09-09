#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int n, mas[10], num;
vector <string> ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num != 1 && num != 2 && num != 3 && num != 4 && num != 6) {
            cout << "-1";
            return 0;
        }
        ++mas[num];
    }

    while (n > 0) {
        //cout << "@";
        if (mas[1] > 0 && mas[2] > 0 && mas[4] > 0) {
            --mas[1];
            --mas[2];
            --mas[4];
            ans.push_back("1 2 4\n");
        } else if (mas[1] > 0 && mas[2] > 0 && mas[6] > 0) {
            --mas[1];
            --mas[2];
            --mas[6];
            ans.push_back("1 2 6\n");
        } else if (mas[1] > 0 && mas[3] > 0 && mas[6] > 0) {
            --mas[1];
            --mas[3];
            --mas[6];
            ans.push_back("1 3 6\n");
        } else {
            cout << "-1";
            return 0;
        }
        n -= 3;
    }

    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i];    
    }

    return 0;
}
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int k;
    int m;
    vector <int> fisha;
    vector <int> fishb;
    cin >> n >> m >> k;
    for (int  i = 0; i < n; ++i) {
        int term;
        cin >> term;
        fisha.push_back(term - 1);
    }
    for (int  i = 0; i < m; ++i) {
        int term;
        cin >> term;
        fishb.push_back(term - 1);
    }
    sort(fisha.begin(), fisha.end());
    sort(fishb.begin(), fishb.end());
        int j = 0;
    for (int i = 0; i < n; ++i) {
        for (; j < m; ++j) {
            if (fishb[j] >= fisha[i]) {
                fishb[j] = 0;
                break;
            }
        }
        if (j == m) {
            cout << "YES";  
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
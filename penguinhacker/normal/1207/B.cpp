#include <iostream>
#include <vector>
using namespace std;

int arr[50][50], ans[50][50];

int main() {
    int n,m,a,b,t;
    a = 0;
    b = 0;
    cin >> n >> m;
    a = n;
    b = m;
    t = 0;
    while (a--) {
        b = m;
        while (b--) {
            cin >> t;
            arr[n-a-1][m-b-1] = t;
        }
    }
    vector<pair<int,int>>moves;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            if (arr[i][j] == 1 && arr[i+1][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j+1] == 1) {
                moves.push_back({i+1, j+1});
                ans[i][j] = 1;
                ans[i+1][j] = 1;
                ans[i][j+1] = 1;
                ans[i+1][j+1] = 1;
            }
        }
    }
    bool noSol = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != ans[i][j]) {
                cout << "-1";
                noSol = true;
                return 0;
            }
        }
    }
    if (!noSol) {
        cout << moves.size() << "\n";
        for (int i = 0; i < moves.size(); i++) {
            auto pa = moves[i];
            cout << pa.first << " " << pa.second << "\n";
        }
    }
    return 0;
}
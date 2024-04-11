#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 110;

vector<int> moves;
int row[N], col[N];
int data[N][N];
int n, m;

int main( void ) {

	cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> data[i][j];
        }
    }

    bool found = false;
    for (int val = 0; val <= data[0][0]; ++val) {
        
        bool err = false;
        int sum = 0;
        row[0] = val;
        for (int j = 0; j < m; ++j) {
            col[j] = data[0][j] - row[0];
            if (col[j] < 0) err = true;
            sum += col[j];
        }
        for (int i = 0; i < n; ++i) {
            row[i] = data[i][0] - col[0];
            if (row[i] < 0) err = true;
            sum += row[i];
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (row[i] + col[j] != data[i][j]) {
                    err = true;
                }
            }
        }

        if (err) continue;
        if (found and sum > moves.size()) continue;
        found = true;
        
        moves.clear();
        for (int i = 0; i < n; ++i) {
            while (row[i] > 0) {
                moves.push_back(i+1);
                --row[i];
            }
        }
        for (int j = 0; j < m; ++j) {
            while (col[j] > 0) {
                moves.push_back(-j-1);
                --col[j];
            }
        }
    }

    if (!found) {
        cout << -1 << endl;
    } else {
        cout << moves.size() << endl;
        for (int val : moves) {
            if (val > 0) cout << "row " << val << endl;
            else cout << "col " << (-val) << endl;
        }
    }
	return 0;

}
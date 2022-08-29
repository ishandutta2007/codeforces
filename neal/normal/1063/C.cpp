#include <iostream>
using namespace std;

string query(int x, int y) {
    cout << x << ' ' << y << endl;
    string result;
    cin >> result;
    return result;
}

int main() {
    int N;
    cin >> N;
    string start = query(0, 1);
    int low = 0, high = 1e9;

    for (int i = 1; i < N; i++) {
        int mid = (low + high) / 2;

        if (query(mid, 1) == start)
            low = mid;
        else
            high = mid;
    }

    cout << low << ' ' << 0 << ' ' << high << ' ' << 2 << endl;
}
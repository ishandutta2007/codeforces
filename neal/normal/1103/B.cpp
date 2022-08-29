#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool query(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    string result;
    cin >> result;

    if (result == "e")
        exit(0);

    return result == "x";
}

int main() {
    string situation;

    while (true) {
        cin >> situation;

        if (situation == "mistake" || situation == "end")
            return 0;

        assert(situation == "start");
        int x = 1;

        while (!query(x, 2 * x))
            x = 2 * x + 1;

        // a is between x and 2 * x
        int low = x, high = 2 * x;

        while (low + 1 < high) {
            int mid = (low + high) / 2;

            if (mid % 2 == 1)
                mid--;

            if (query(mid / 2, mid))
                high = mid;
            else
                low = mid + 1;
        }

        if (low == high) {
            cout << "! " << low << endl;
        } else {
            assert(low + 1 == high);

            if (query(low - 1, low))
                high = low;
            else
                low = high;

            cout << "! " << low << endl;
        }
    }
}
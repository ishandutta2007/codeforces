#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));

const int QUERIES = 60;

int queries = 0;
int N;

int main() {
    cin >> N;
    int low = 0, high = 1e9;

    while (low < high) {
        int mid = (low + high) / 2;

        queries++;
        cout << "> " << mid << endl;
        int result;
        cin >> result;

        if (result == 0)
            high = mid;
        else
            low = mid + 1;
    }

    int largest = low, diff = 0;

    while (queries < QUERIES) {
        int index = uniform_int_distribution<int>(1, N)(rng);

        queries++;
        cout << "? " << index << endl;
        int result;
        cin >> result;
        diff = __gcd(diff, largest - result);
    }

    cout << "! " << largest - diff * (N - 1) << ' ' << diff << endl;
}
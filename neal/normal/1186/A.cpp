#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    cout << (min(M, K) >= N ? "Yes" : "No") << '\n';
}
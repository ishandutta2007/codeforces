#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[3] = { 0, };
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        arr[temp]++;
    }
    cout << min(arr[2], arr[1]) + max(0, (arr[1] - arr[2]) / 3);
    //system("pause");
    return 0;
}
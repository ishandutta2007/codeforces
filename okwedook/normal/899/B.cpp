#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <deque>

using namespace std;
int arr1[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int arr2[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void printYES() {
    cout << "YES";
    exit(0);
}

bool check1(vector<int> arr, int from) {
    for (int i = from; i < from + arr.size(); ++i)
        if (arr[i - from] != arr1[i])
            return false;
    return true;
}


bool check2(vector<int> arr, int from) {
    for (int i = from; i < from + arr.size(); ++i)
        if (arr[i - from] != arr2[i])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    for (int i = 0; i < 24; ++i)
        if (check1(arr, i) || check2(arr, i)) printYES();
    cout << "NO";
    //system("pause");
    return 0;
}
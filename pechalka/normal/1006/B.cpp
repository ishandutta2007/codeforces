#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        A[i] = {a, i};
    }
    sort(A.begin(), A.end());
    if (k == 1){
        cout << A.back().first << endl << n;
        return 0;
    }
    vector<int> B(k);
    for (int i = 0; i < k; ++i)
        B[i] = A[n - i - 1].second;
    sort(B.begin(), B.end());
    int sum = 0;
    for (int i = 0; i < k; ++i)
        sum += A[n - i - 1].first;
    cout << sum << endl << B[0] + 1 << " ";
    for (int i = 1; i < k - 1; ++i)
        cout << B[i] - B[i - 1] << " ";
    cout << n - B[k - 2] - 1;
    return 0;
}
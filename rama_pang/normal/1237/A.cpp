#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), ans(N), odd;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] % 2 == 0) {
            ans[i] = A[i] / 2;
        } else {
            odd.push_back(i);
        }
    }
    if (odd.size() % 2 == 0) {
        for (int i = 0; i < odd.size() / 2; i++) {
            ans[odd[i]] = (A[odd[i]] + 1) / 2; 
        }
        for (int i = odd.size() / 2; i < odd.size(); i++) {
            ans[odd[i]] = (A[odd[i]] - 1) / 2; 
        }
    } else {
        
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
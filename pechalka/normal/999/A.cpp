#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        if (A[i] <= k)
            ans[i][i] = 1;
    for (int d = 1; d < n; ++d)
        for (int l = 0; l + d < n; l++){
            if (A[l] <= k)
                ans[l][l + d] = ans[l + 1][l + d] + 1;
            if (A[l + d] <= k && ans[l][l + d - 1] + 1 > ans[l][l + d])
                ans[l][l + d] = ans[l][l + d - 1] + 1;
        }
    cout << ans[0][n - 1];
    return 0;
}
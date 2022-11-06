#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    int n;
    cin >> n;
    if((n & 1) == 0) cout << "No";
    else {
        int arr[110];
        for(int i = 0; i < n; i++) cin >> arr[i];
        if((arr[0] & 1) == 0 || (arr[n-1] & 1) == 0) cout << "No";
        else cout << "Yes";
    }
    return 0;
}
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lint = long long;

int main() {
    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    
    if (arr[0] + arr[1] == arr[2] + arr[3]) {
        cout << "YES\n";
        return 0;
    }
    if (arr[0] + arr[2] == arr[1] + arr[3]) {
        cout << "YES\n";
        return 0;
    }
    if (arr[0] + arr[3] == arr[2] + arr[1]) {
        cout << "YES\n";
        return 0;
    }
    if (arr[2] + arr[1] == arr[0] + arr[3]) {
        cout << "YES\n";
        return 0;
    }
    if (arr[3] + arr[1] == arr[2] + arr[0]) {
        cout << "YES\n";
        return 0;
    }
    if (arr[0] + arr[2] == arr[1] + arr[3]) {
        cout << "YES\n";
        return 0;
    }
    if (arr[0] + arr[1] + arr[2] == arr[3]) {
        cout << "YES\n";
        return 0;
    }
    if (arr[0] + arr[1] + arr[3] == arr[2]) {
        cout << "YES\n";
        return 0;
    }
    if (arr[0] + arr[2] + arr[3] == arr[1]) {
        cout << "YES\n";
        return 0;
    }
    if (arr[3] + arr[1] + arr[2] == arr[0]) {
        cout << "YES\n";
        return 0;
    }
    
    cout << "NO\n";
}
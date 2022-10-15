#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[101010];

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++) {
        if (i%2 == 0) {
            a[i] = v[n/2+i/2];
        } else {
            a[i] = v[i/2];
        }
    }
    int c = 0;
    for (int i = 1; i < n-1; i++) {
        if (a[i-1] > a[i] && a[i] < a[i+1]) c++;
    }
    cout << c << "\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}
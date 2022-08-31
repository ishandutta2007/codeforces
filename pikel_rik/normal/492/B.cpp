#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    
    cout << fixed;
    
    vector<double> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    double m = a[0];
    for (int i = 1; i < n; i++) {
        if ((a[i] - a[i-1])/2 > m) {
            m = (a[i] - a[i-1])/2;
        }
    }

    if (l - a[a.size()-1] > m)
        m = l - a[a.size()-1];
        
    cout << setprecision(10) << m;
    return 0;
}
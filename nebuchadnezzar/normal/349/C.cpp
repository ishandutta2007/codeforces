#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> mas;
long long sum, maxn, num;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> num;
        mas.push_back(num);
        maxn = max(maxn, num);
        sum += num;
    }
    
    //sort(mas.begin(), mas.end());
    /*
    if (mas[0] == mas[mas.size() - 1]) {
        cout << mas[0] + 1;
        return 0;
    }

    int c = 0;
    while (sum < mas[mas.size() - 1]) {
        sum += mas[c];
        ++c;
    }

    */
    /*
    long long l = 0, r = sum;
    while (r - l > 1) {
        long long m = (l + r) / 2;
        cout << (m + sum + n - 1) / n << " " << m << endl;
        if ((m + sum + n - 1) / n >= m) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;

    cout << (r + sum + n - 1) / n;
    */
    cout << max((sum + n - 2) / (n - 1), maxn);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
int c;
vector<int> v;
ll s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x%2 == 1) c++;
        v.push_back(x);
    }
    c %= 2;
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++) {
        if (v[i]%2 == 1 && c) {c = 0; continue;}
        s += v[i];
    }
    cout << s << "\n";
}
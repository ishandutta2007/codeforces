#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n;
vector<int> v;
int c;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    deque<int> a;
    for (int i = 0; i < v.size(); i++) {
        if (a.size() && a.front() < v[i]) {
            c++;
            a.pop_front();
        }
        a.push_back(v[i]);
    }
    cout << c << "\n";
}
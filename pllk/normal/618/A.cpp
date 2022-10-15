#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        v.push_back(1);
        while (v.size() >= 2 && v[v.size()-1] == v[v.size()-2]) {
            int u = v[v.size()-1]+1;
            v.pop_back();
            v.pop_back();
            v.push_back(u);
        }
    }
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\n";
}
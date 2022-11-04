#include <bits/stdc++.h>

using namespace std;

vector <int> v;

int main() {
    int n;
    cin >> n;
    while(n % 10 == 0)
        n /= 10;
    while(n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    int i = 0;
    while(i < v.size() - i - 1 && v[i] == v[v.size() - i - 1])
        i++;
    if(i >= v.size() - i - 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
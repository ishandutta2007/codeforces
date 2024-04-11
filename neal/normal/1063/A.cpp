#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    string str;
    cin >> N >> str;
    sort(str.begin(), str.end());
    cout << str << '\n';
}
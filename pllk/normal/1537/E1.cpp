#include <iostream>

using namespace std;

int n, k;
string s;

int main() {
    cin >> n >> k;
    cin >> s;
    string r = "";
    while (s != "") {
        string u = "";
        while (u.size() < k) u += s;
        while (u.size() > k) u.pop_back();
        if (r == "" || u < r) r = u;
        s.pop_back();
    }
    cout << r << "\n";
}
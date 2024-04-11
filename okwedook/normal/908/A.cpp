#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() { 
    string s;
    cin >> s;
    ll count = 0;
    for (auto i : s) {
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || (i < 60 && (i - 48) % 2 == 1))
            ++count;
    }
    cout << count;
    //system("pause");
    return 0; 
}
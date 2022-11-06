#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string word;
    cin >> n;
    while (n--) {
        cin >> word;
        if (word.length() > 10) {
            cout << word[0] << word.length() - 2 << word[word.length() - 1];
        } else {
            cout << word;
        }
        cout << "\n";
    }
}
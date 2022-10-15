#include <iostream>

using namespace std;

int n;
string s;
int c[10];

int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') continue;
        if (s[i] == '1') continue;
        if (s[i] >= '2') c[2]++;
        if (s[i] >= '3') c[3]++;
        if (s[i] >= '4') c[2] += 2;
        if (s[i] >= '5') c[5]++;
        if (s[i] >= '6') {c[2]++; c[3]++;}
        if (s[i] >= '7') c[7]++;
        if (s[i] >= '8') c[2] += 3;
        if (s[i] >= '9') c[3] += 2;
    }
    while (c[7]) {cout << 7; c[7]--; c[5]--; c[3] -= 2; c[2] -= 4;}
    while (c[5]) {cout << 5; c[5]--; c[3]--; c[2] -= 3;}
    while (c[3]) {cout << 3; c[3]--; c[2]--;}
    while (c[2]) {cout << 2; c[2]--;}
    cout << "\n";
}
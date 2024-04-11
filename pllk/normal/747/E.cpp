#include <iostream>
#include <vector>

using namespace std;

string s;
int k;
int a;
vector<string> v[1222333];

void lol(int d) {
    a = max(a,d);
    string c;
    for (; ; k++) {
        if (s[k] == ',') {
            break;
        } else {
            c += s[k];
        }
    }
    v[d].push_back(c);
    int u = 0;
    for (k++; ; k++) {
        if (s[k] == ',') {
            break;
        } else {
            u = u*10+s[k]-'0';
        }
    }
    k++;
    for (int i = 0; i < u; i++) lol(d+1);
}

int main() {
    cin >> s;
    s += ",";
    while (k != s.size()) lol(0);
    cout << a+1 << "\n";
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
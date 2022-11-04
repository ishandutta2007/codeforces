#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

int fr[3];
string str;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> str;
    for(char ch = 2; ch >= 0; ch--) {
        while(str.back() == ch + 'a') {
            str.pop_back();
            fr[ch]++;
        }
    }
    if(str.empty() && (fr[0] == fr[2] || fr[1] == fr[2]) && fr[0] && fr[1]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    //cin.close();
    //cout.close();
    return 0;
}
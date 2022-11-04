#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string str;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    ios::sync_with_stdio(false);
    cin >> str;
    int a = 0, b = 0;
    for(auto it : str) {
        if(it == '-') {
            a++;
        }
        else {
            b++;
        }
    }
    if(b == 0 || (a % b == 0)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string str1, str2;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> str1 >> str2;
    if(str1 == str2) {
        cout << "YES";
        return 0;
    }
    int cnt = 0;
    for(auto it : str1) {
        if(it == '*') {
            cnt = 1;
        }
    }
    if(str1.size() - cnt > str2.size()) {
        cout << "NO";
        return 0;
    }
    while(str1.back() == str2.back()) {
        str1.pop_back();
        str2.pop_back();
    }
    if(str1.back() != '*') {
        cout << "NO";
        return 0;
    }
    int i = 0;
    while(i < str1.size() && i < str2.size() && str1[i] == str2[i]) {
        i++;
    }
    if(str1[i] != '*') {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    //cin.close();
    //cout.close();
    return 0;
}
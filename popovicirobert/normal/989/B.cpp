#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

string str;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, p;
    ios::sync_with_stdio(false);
    cin >> n >> p;
    cin >> str;
    bool flag = 0;
    for(i = 0; i < n - p; i++) {
        int pos = i + p;
        while(pos < n && str[pos] == str[i]) {
            pos += p;
        }
        if(pos < n) {
            if(str[i] == '.') {
                if(str[pos] == '1')
                    str[i] = '0';
                else
                    str[i] = '1';
            }
            else if(str[pos] == '.') {
                if(str[i] == '1')
                    str[pos] = '0';
                else
                    str[pos] = '1';
            }
            flag = 1;
            break;
        }
        else if(str[i] == '.') {
            flag = 1;
            str[i] = '1';
            str[i + p] = '0';
            break;
        }
    }
    if(!flag) {
        cout << "No";
        return 0;
    }
    for(auto &it : str) {
        if(it == '.')
            it = '0';
    }
    cout << str;
    //cin.close();
    //cout.close();
    return 0;
}
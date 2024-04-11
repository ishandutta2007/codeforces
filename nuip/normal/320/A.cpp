#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

int main() {

    string str;
    cin >> str;

    int sz = str.size();

    for(int i = 0; i < sz; ++i) {
        if(str[i] == '1') {
            if(i + 1 < sz && str[i+1] == '4') {
                if(i + 2 < sz && str[i+2] == '4') {
                    i += 2;
                    continue;
                }
                else {
                    i += 1;
                    continue;
                }
            }
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
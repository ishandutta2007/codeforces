#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    int last = -1, len = 0;
    int len0, len1;
    int cnt0 = 0, cnt1 = 0;
    for(i = 1; i <= n; i++) {
        cin >> x;
        if(last == x) {
            len++;
        }
        else {
            if(last == 0) {
                if(cnt0 == 0) {
                    len0 = len;
                }
                else if(len0 != len) {
                    cout << "NO";
                    return 0;
                }
                cnt0++;
            }
            else if(last == 1) {
                if(cnt1 == 0) {
                    len1 = len;
                }
                else if(len1 != len) {
                    cout << "NO";
                    return 0;
                }
                cnt1++;
            }
            last = x;
            len = 1;
        }
    }
    if(last == 0) {
        if(cnt0 == 0) {
            len0 = len;
        }
        else if(len0 != len) {
            cout << "NO";
            return 0;
        }
        cnt0++;
    }
    else {
        if(cnt1 == 0) {
            len1 = len;
        }
        else if(len1 != len) {
            cout << "NO";
            return 0;
        }
        cnt1++;
    }
    if(cnt0 == 0) {
        len0 = len1;
    }
    if(cnt1 == 0) {
        len1 = len0;
    }
    if(len1 == len0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    //cin.close();
    //cout.close();
    return 0;
}
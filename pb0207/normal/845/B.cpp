#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define N 110 
#define M 90010
#define LL __int64
#define inf 0x3f3f3f3f
#define lson l,mid,ans<<1
#define rson mid+1,r,ans<<1|1
#define getMid (l+r)>>1
#define movel ans<<1
#define mover ans<<1|1
using namespace std;
const LL mod = 1e9 + 7;
int num[N];
int main() {
    cin.sync_with_stdio(false);
    string str;
    int numa[3], numb[3], a, b;
    while (cin >> str) {
        a = 0, b = 0;
        for (int i = 0; i < 3; i++) {
            numa[i] = str[i] - '0';
            a += numa[i];
        }
        for (int i = 3; i < 6; i++) {
            numb[i-3] = str[i] - '0';
            b += numb[i - 3];
        }
        sort(numa, numa + 3);
        sort(numb, numb + 3);
        if (a > b) {
            swap(numa, numb);
            swap(a, b);
        }
        int num = b - a;
        if (a != b) {
            if (num <= 9 - numa[0] || num <= numb[2]) cout << 1 << endl;
            else if (num <= 18 - numa[0] - numa[1] || num <= numb[1] + numb[2] || num <= 9 - numa[0] + numb[2]) cout << 2 << endl;
            else cout << 3 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

string a, b, c;
int fr[1000];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    int mxa = 0, mxb = 0, mxc = 0;
    int sz = a.size();
    for(auto it : a) {
        fr[it]++;
    }
    for(i = 0; i < 300; i++) {
        if(!isalpha(i))
            continue;
        if(n != 1) {
            mxa = max(mxa, min(sz, fr[i] + n));
        }
        else if(fr[i] == sz) {
            mxa = max(mxa, sz - 1);
        }
        else {
            mxa = max(mxa, fr[i] + 1);
        }
    }
    memset(fr, 0, sizeof(fr));
    for(auto it : b) {
        fr[it]++;
    }
    for(i = 0; i < 300; i++) {
        if(!isalpha(i))
            continue;
        if(n != 1) {
            mxb = max(mxb, min(sz, fr[i] + n));
        }
        else if(fr[i] == sz) {
            mxb = max(mxb, sz - 1);
        }
        else {
            mxb = max(mxb, fr[i] + 1);
        }
    }
    memset(fr, 0, sizeof(fr));
    for(auto it : c) {
        fr[it]++;
    }
    for(i = 0; i < 300; i++) {
        if(!isalpha(i))
            continue;
        if(n != 1) {
            mxc = max(mxc, min(sz, fr[i] + n));
        }
        else if(fr[i] == sz) {
            mxc = max(mxc, sz - 1);
        }
        else {
            mxc = max(mxc, fr[i] + 1);
        }
    }
    if(mxa > max(mxb, mxc)) {
        cout << "Kuro";
        return 0;
    }
    if(mxb > max(mxa, mxc)) {
        cout << "Shiro";
        return 0;
    }
    if(mxc > max(mxa, mxb)) {
        cout << "Katie";
        return 0;
    }
    cout << "Draw";
    //cin.close();
    //cout.close();
    return 0;
}
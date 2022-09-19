#include <bits/stdc++.h>

using namespace std;
const int c=1002;
int n, x, a, b;
vector<pair<int, int> > sz;
bool t[c][c];
int main()
{
    cin >> n;
    sz.push_back({1, n+1});
    for (int i=1; i<=n; i++) {
        while(sz.back().first==sz.back().second) sz.pop_back();
        cin >> x;
        a=sz.back().first, b=sz.back().second;
        int pos=a-1;
        while(x) {
            pos++;
            if (pos==n+2) pos=1;
            if (pos!=b) t[pos][i]=1, x--;
        }
        if (pos<a || pos>=b) sz.back().second--;
        else {
            sz.pop_back();
            sz.push_back({a, pos});
            sz.push_back({pos+1, b});
        }
    }
    cout << n+1 << "\n";
    for (int i=1; i<=n+1; i++) {
        for (int j=1; j<=n; j++) cout << t[i][j];
        cout << "\n";
    }
    return 0;
}
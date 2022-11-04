#include <bits/stdc++.h>
#define MAXN 500000

using namespace std;

string str;
int v[MAXN + 1];

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int i,n;
    cin >> n;
    long long s = 0;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    cin >> str;
    str.push_back(0);
    for(i = str.size() - 1; i >= 0; i--)
        str[i + 1] = str[i];
    for(i = 1; i <= n; i++)
        if(str[i] == 'B')
           s += v[i];
    long long x = 0;
    long long ans = s;
    for(i = 1; i <= n; i++) {
        if(str[i] == 'B')
            x -= v[i];
        else
            x += v[i];
        if(s + x > ans)
            ans = s + x;
    }
    x = 0;
    for(i = n; i >= 1; i--) {
        if(str[i] == 'B')
            x -= v[i];
        else
            x += v[i];
        if(s + x > ans)
            ans = s + x;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
const int c=52;
bool v[c][c];
int n, kom[c][c], dp[c][c][c][c];
int sor(int a, int c, int d)
{
    return kom[a][d]-kom[a][c-1]-kom[a-1][d]+kom[a-1][c-1];
}
int oszlop(int c, int a, int b)
{
    return kom[b][c]-kom[a-1][c]-kom[b][c-1]+kom[a-1][c-1];
}
int ter(int a, int b, int c, int d)
{
    return kom[b][d]-kom[a-1][d]-kom[b][c-1]+kom[a-1][c-1];
}
int solve(int a, int b, int c, int d)
{
    if (a>b || c>d) {
        return 0;
    }
    int p=ter(a, b, c, d);
    if (p<=2) {
        dp[a][b][c][d]=p+100;
        return p;
    }
    while(sor(a, c, d)==0) {
        a++;
    }
    while(sor(b, c, d)==0) {
        b--;
    }
    while(oszlop(c, a, b)==0) {
        c++;
    }
    while(oszlop(d, a, b)==0) {
        d--;
    }
    if (dp[a][b][c][d]!=0) {
        return dp[a][b][c][d]-100;
    }
    vector<int> s;
    vector<int> o;
    for (int i=a; i<=b; i++) {
        if (sor(i, c, d)==0) {
            if (s.size()==0 || i-s.back()>1) {
                s.push_back(i);
            }
        }
    }
    s.push_back(b+1);
    for (int i=c; i<=d; i++) {
        if (oszlop(i, a, b)==0) {
            if (o.size()==0 || i-o.back()>1) {
                o.push_back(i);
            }
        }
    }
    o.push_back(d+1);
    int mini=max(b-a+1, d-c+1);
    for (int i=0; i<s.size(); i++) {
        for (int j=0; j<o.size(); j++) {
            int x=s[i], y=o[j];
            if (x<=b || y<=d) {
                mini=min(mini, solve(a, x-1, c, y-1)+solve(a, x-1, y+1, d)+solve(x+1, b, c, y-1)+solve(x+1, b, y+1, d));
            }
        }
    }
    dp[a][b][c][d]=mini+100;
    return mini;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            char c;
            cin >> c;
            if (c=='#') {
                v[i][j]=true;
            }
            kom[i][j]=kom[i-1][j]+kom[i][j-1]-kom[i-1][j-1]+v[i][j];
        }
    }
    cout << solve(1, n, 1, n);
    return 0;
}
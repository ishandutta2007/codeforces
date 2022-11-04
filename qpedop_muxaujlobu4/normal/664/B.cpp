#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string s="",tp="";
    while (tp != "=") {
        cin >> tp;
        if (tp != "?")
            s += tp;
    }
    cin >> tp;
    s += tp;
    int i,k=0,k1=0,len=s.length();
    for (i = 0; i < len; ++i) {
        if (s[i] == '-')++k;
        if (s[i] == '+')++k1;
        if (s[i] == '=')break;
    }
    i += 1;
    int x = 0;
    for (; i < len; ++i)x = x * 10 + s[i] - '0';
    if (x * (k1 + 1) - k < x) {
        cout << "Impossible";
        return 0;
    }
    if (k1 + 1 - k * x > x) {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible\n";
    int T = max(1 + k1, k + x);
    int F = T, S = T - x;
    {
        int tmp = F - k1;
        if (tmp > x)tmp = x;
        F -= tmp;
        cout << tmp;
    }
  //  cout << F << endl;
    --k1;
    for (int i1 = 0; s[i1] != '='; ++i1) {
        if (s[i1] == '+') {
            int tmp = F - k1;
            if (tmp > x)tmp = x;
            F -= tmp;
            --k1;
            cout << " + " << tmp;
        }
        if (s[i1] == '-') {
            int tmp = S - k + 1;
            if (tmp > x)tmp = x;
            S -= tmp;
            --k;
            cout << " - " << tmp;
        }
    }
    cout << " = " << x;
    return 0;
}
/*
5 6
1 2
1 3
2 4
2 5
3 1
4 2
*/
// 1 2 6 3 2 4 5 3 1
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

int n, m, q[maxn], a, b, c;

int check(string s){
    if (s == "monday")
        return 1;
    if (s == "tuesday")
        return 2;
    if (s == "wednesday")
        return 3;
    if (s == "thursday")
        return 4;
    if (s == "friday")
        return 5;
    if (s == "saturday")
        return 6;
    return 0;
}

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    a = check(s);
    cin >> s;
    b = check(s);
    q[0] = 28;
    q[1] = 30;
    q[2] = 31;
    for (int i = 0; i < 3; i++)
    if ((a + q[i]) % 7 == b){
        cout << "YES";
        return 0;
    }
    cout << "NO";
}
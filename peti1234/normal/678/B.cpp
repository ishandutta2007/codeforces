#include <bits/stdc++.h>

using namespace std;
bool leap(int x) {
    return (x%400==0 || x%4==0 && x%100);
}
int s, n, db;
int main()
{
    cin >> n;
    s=leap(n);
    do {
        n++;
        db++, db+=leap(n);
    } while (s!=leap(n) || db%7);
    cout << n << "\n";
    return 0;
}
/*
50501
*/
#include <bits/stdc++.h>

using namespace std;
int a, b, c, d, db;
string x, y;
bool v[12][12];
void add(int a, int b) {
    if (a>0 && b>0) v[a][b]=true;
}
int main()
{
    cin >> x >> y;
    a=x[0]-'a'+1, b=x[1]-'0', c=y[0]-'a'+1, d=y[1]-'0';
    for (int i=1; i<=8; i++) add(a, i), add(i, b);
    add(a, b);
    add(a+2, b+1);
    add(a+2, b-1);
    add(a-2, b+1);
    add(a-2, b-1);
    add(a+1, b+2);
    add(a+1, b-2);
    add(a-1, b+2);
    add(a-1, b-2);
    add(c, d);
    add(c+2, d+1);
    add(c+2, d-1);
    add(c-2, d+1);
    add(c-2, d-1);
    add(c+1, d+2);
    add(c+1, d-2);
    add(c-1, d+2);
    add(c-1, d-2);
    for (int i=1; i<=8; i++) for (int j=1; j<=8; j++) db+=1-v[i][j];
    cout << db << "\n";
    return 0;
}
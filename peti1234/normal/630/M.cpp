#include <bits/stdc++.h>

using namespace std;
long long n, db;
int main()
{
    cin >> n;
    n%=360, n+=3600;
    while(n%360<315 && n%360>45) n-=90, db++;
    cout << db << endl;
    return 0;
}
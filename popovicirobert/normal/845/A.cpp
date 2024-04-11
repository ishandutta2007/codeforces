#include <bits/stdc++.h>
#define ll long long


using namespace std;


int v[200000];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= 2 * n; i++)
         cin >> v[i];
    sort(v + 1, v + 2 * n + 1);
    if(v[n] < v[n + 1])
         cout << "YES";
    else
          cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}
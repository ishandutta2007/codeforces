#include <bits/stdc++.h>


using namespace std;

int v[10000];

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i,n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    i = 1;
    while(i < n && v[i + 1] > v[i])
        i++;
    /*if(v[i] != v[i + 1]) {
        cout << "NO";
        return 0;
    } */
    while(i < n && v[i] == v[i + 1])
        i++;
    while(i < n && v[i] > v[i + 1])
        i++;
    if(i == n)
        cout << "YES";
    else
        cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}
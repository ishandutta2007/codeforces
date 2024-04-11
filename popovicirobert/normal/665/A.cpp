#include <bits/stdc++.h>


using namespace std;



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int ans = 0;
    int a, ta, b, tb, hh, mm;
    char ch;
    //ios::sync_with_stdio(false);
    cin >> a >> ta >> b >> tb;
    cin >> hh >> ch >> mm;
    for(int i = 300; i < 24 * 60; i++)
        if((i - 300) % b == 0 && i + tb > hh * 60 + mm && hh * 60 + mm + ta > i)
            ans++;
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
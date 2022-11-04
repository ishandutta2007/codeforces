#include <bits/stdc++.h>
#define ll long long


using namespace std;

string str;
int fr[26];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> str;
    for(auto it : str)
        fr[it - 'a']++;
    int mx = 0;
    for(i = 0; i < 26; i++)
        mx = max(mx, fr[i]);
    if(mx <= k)
        cout << "YES";
    else
        cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}
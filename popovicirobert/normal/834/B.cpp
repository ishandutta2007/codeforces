#include <bits/stdc++.h>
#define ll long long


using namespace std;



string str;

int last[26];
bool ok[26];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, k, i;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    cin >> str;
    for(i = 0; i < n; i++) {
        str[i] -= 'A';
        last[str[i]] = i;
    }
    for(i = 0; i < n; i++) {
         if(ok[str[i]] == 0) {
            ok[str[i]] = 1;
            k--;
            if(k < 0) {
                cout << "YES";
                return 0;
            }
        }
        if(last[str[i]] == i)
            k++;
    }
    cout << "NO";
    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    if(n == 1){
        cout << "Yes";
        return 0;
    }
    int val[26];
    fill(val, val + 26, 0);
    for(int i = 0; i<n; i++){
        val[s[i] - 'a']++;
        if(val[s[i] - 'a'] == 2){
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
}
#include "bits/stdc++.h"
using namespace std;
string str;
int mx;
int main(){
    cin >> str;
    mx = 0;
    for(char c : str){
        int x = c - 'a' + 1;
        if(x > mx + 1){
            cout << "NO\n";
            return 0;
        }
        mx = max(mx , x);
    }
    cout << "YES\n";
}
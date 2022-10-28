#include "bits/stdc++.h"
using namespace std;
string str;
int main(){
    cin >> str;
    int ans = 0;
    for(string::iterator it = str.begin() ; it != str.end() ; ++it){
        ans = ans + ans + ( (*it == '4') ? 1 : 2 );
    }
    cout << ans ;
}
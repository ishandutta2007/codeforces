#include "bits/stdc++.h"
using namespace std;
string str1;
string str2;
int n , m;
int ans = 0;
int main(){
    cin >> str1 >> str2;
    n = str1.size();
    m = str2.size();
    for(int i = 0 ; i <= n - m ; ++i){
        if(str1.substr(i , m) == str2){
            str1[i + m - 1] = '#';
            ++ans;
        }
    }
    cout << ans;
}
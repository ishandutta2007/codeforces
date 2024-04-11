#include "bits/stdc++.h"
using namespace std;
string str;
int cnt[2];
int main(){
    cin >> str;
    cin >> str;
    for(auto x : str){
        cnt[x - '0']++;
    }
    cout << abs(cnt[0] - cnt[1]);
}
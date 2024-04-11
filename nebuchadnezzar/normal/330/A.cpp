#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int r, c;
bool masr[10], masc[10];
string s;


int main(){
    cin >> r >> c;
    for(int i = 0; i < r; ++i){
        cin >> s;
        for(int j = 0; j < c; ++j){
            if(s[j] == 'S'){
                masr[i] = true;
                masc[j] = true;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(not masr[i] || not masc[j]){
                ++ans;
            }
        }
    }
    cout << ans;

    return 0;
}
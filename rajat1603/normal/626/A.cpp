#include "bits/stdc++.h"
using namespace std;
const int N = 205;
int n;
string str;
int ans = 0;
int main(){
    cin >> n;
    cin >> str;
    for(int i = 0 ; i < n ; ++i){
        int x = 0;
        int y = 0;
        for(int j = i ; j < n ; ++j){
            if(str[j] == 'U'){
                --x;
            }
            else if(str[j] == 'D'){
                ++x;
            }
            else if(str[j] == 'L'){
                --y;
            }
            else if(str[j] == 'R'){
                ++y;
            }
            if(x == 0 && y == 0){
                ++ans;
            }
        }
    }
    cout << ans;
}
#include "bits/stdc++.h"
using namespace std;
string str;
int m;
int l , r , k;
int main(){
    cin >> str;
    cin >> m;
    while(m--){
        cin >> l >> r >> k;
        string temp = "";
        for(int i = l - 1 ; i < r ; ++i){
            temp += str[i];
        }
        k %= int(temp.size());
        string temp2 = temp;
        for(int i = 0 ; i < temp.size() ; ++i){
            temp[i] = temp2[(i - k + r - l + 1) % (r - l + 1)];
        }
        for(int i = l - 1 ; i < r ; ++i){
            str[i] = temp[i - l + 1];
        }
    }
    cout << str;
}
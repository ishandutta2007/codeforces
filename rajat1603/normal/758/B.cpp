#include "bits/stdc++.h"
using namespace std;
string str;
int cnt[4];
map < char , int > mp;
int main(){
    cin >> str;
    for(int i = 0 ; i < str.size() ; ++i){
        if(str[i] == '!'){
            ++cnt[i % 4];
        }
        else{
            mp[str[i]] = i % 4;
        }
    }
    cout << cnt[mp['R']] << " " << cnt[mp['B']] << " " << cnt[mp['Y']] << " " << cnt[mp['G']] << endl;
}
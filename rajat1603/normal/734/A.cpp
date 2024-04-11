#include "bits/stdc++.h"
using namespace std;
int n;
string str;
map < char , int > mp;
int main(){
    cin >> n;
    cin >> str;
    for(char c : str){
        ++mp[c];
    }
    if(mp['A'] > mp['D']){
        cout << "Anton\n";
    }
    else if(mp['A'] < mp['D']){
        cout << "Danik\n";
    }
    else{
        cout << "Friendship\n";
    }
}
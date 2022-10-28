#include "bits/stdc++.h"
using namespace std;
string str1 , str2;
map < char , char > mp;
int main(){
    cin >> str1 >> str2;
    for(int i = 0 ; i < str1.size() ; ++i){
        mp[str2[i]] = str1[i];
        mp[str1[i]] = str2[i];
    }
    for(int i = 0 ; i < str1.size() ; ++i){
        str2[i] = mp[str2[i]];
    }
    if(str2 != str1){
        cout << "-1\n";
    }
    else{
        for(auto &it : mp){
            if(mp[it.second] != it.first){
                cout << "-1\n";
                return 0;
            }
        }
        set < string > s;
        for(auto it : mp){
            if(it.first < it.second){
                string ss = "";
                ss += it.first;
                ss += " ";
                ss += it.second;
                s.insert(ss);
            }
        }
        cout << int(s.size()) << endl;
        for(auto it : s){
            cout << it << endl;
        }
    }
}
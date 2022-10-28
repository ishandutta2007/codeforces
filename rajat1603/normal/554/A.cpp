#include "bits/stdc++.h"
using namespace std;
string str , temp;
set < string > s;
int main(){
    cin >> str;
    for(int i = 0 ; i <= str.size() ; ++i){
        str.insert(i , " ");
        for(int j = 0 ; j < 26 ; ++j){
            str[i] = 'a' + j;
            s.insert(str);
        }
        str.erase(i , 1);
    }
    cout << s.size();
}
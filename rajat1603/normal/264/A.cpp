#include "bits/stdc++.h"
using namespace std;
string str;
stack<int> s;
int main(){
    cin >> str;
    str = " " + str;
    for(int i = 1 ; i < str.size() ; ++i){
        if(str[i] == 'l'){
            s.push(i);
        }
        else{
            cout << i << "\n";
        }
    }
    while(!s.empty()){
        cout << s.top() << "\n";
        s.pop();
    }
}
#include "bits/stdc++.h"
using namespace std;
int n;
string str;
int main(){
    cin >> n;
    cin >> str;
    if(n == 12){
        if(str[0] == '0' && str[1] == '0'){
            str[1] = '1';
        }
        if(str[0] >= '2'){
            if(str[1] == '0'){
                str[0] = '1';
            }
            else{
                str[0] = '0';
            }
        }
        else if(str[0] == '1' && str[1] > '2'){
            str[1] = '1';
        }
    }
    if(str[3] >= '6'){
        str[3] = '1';
    }
    if(str[0] >= '3'){
        str[0] = '0';
    }
    else if(str[0] == '2' && str[1] > '3'){
        str[1] = '3';
    }
    cout << str << endl;
}
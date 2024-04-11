#include "bits/stdc++.h"
using namespace std;
string str;
int n;
int main(){
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    cin >> str >> n;
    if((str == "front" && n == 1) || (str == "back" && n == 2)){
        cout << "L";
    }
    else{
        cout << "R";
    }
}
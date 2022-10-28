#include "bits/stdc++.h"
using namespace std;
int n;
int a , b;
int x = 0;
int y = 0;
int main(){
    cin >> n;
    while(n--){
        cin >> a >> b;
        x += (a > b);
        y += (b > a);
    }
    if(x > y){
        cout << "Mishka\n";
    }
    else if(x == y){
        cout << "Friendship is magic!^^\n";
    }
    else{
        cout << "Chris\n";
    }
}
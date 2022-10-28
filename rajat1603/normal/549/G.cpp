#include "bits/stdc++.h"
using namespace std;
int n;
set < int > s;
int x;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> x;
        s.insert(x + i);
    }
    if(s.size() == n){
        x = 1;
        for(auto it : s){
            cout << it - x++ << " ";
        }
    }
    else{
        cout << ":(";
    }
}
#include "bits/stdc++.h"
using namespace std;
int main(){
    int sum = 0;
    int temp = 0;
    for(int i = 0 ; i < 5 ; ++i){
        cin >> temp;
        sum += temp;
    }
    if(sum && sum % 5 == 0){
        cout << sum / 5;
    }
    else{
        cout << -1;
    }
}
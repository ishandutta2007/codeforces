#include "bits/stdc++.h"
using namespace std;
const int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string days[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
string a , b;
int leap(int y){
    if(y % 400 == 0){
        return 1;
    }
    if(y % 100 == 0){
        return 0;
    }
    if(y % 4 == 0){
        return 1;
    }
    return 0;
}
int main(){
    cin >> a >> b;
    int x , y;
    for(int i = 0 ; i < 7 ; ++i){
        if(a == days[i]){
            x = i;
        }
        if(b == days[i]){
            y = i;
        }
    }
    int cur = 0;
    for(int j = 0 ; j < 2000 ; ++j){
        for(int i = 0 ; i < 11 ; ++i){
            if(!leap(i)){
                if(cur == x && (cur + arr[i]) % 7 == y){
                    cout << "YES\n";
                    return 0;
                }
            }
            cur += arr[i];
            cur %= 7;
        }
        cur += arr[11];
        cur %= 7;
    }
    cout << "NO\n";
}
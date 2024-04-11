#include "bits/stdc++.h"
using namespace std;
const int N = 10;
string arr[N];
int ans1 = 10;
int ans2 = 10;
int main(){
    for(int i = 1 ; i <= 8 ; ++i){
        cin >> arr[i];
        arr[i] = "." + arr[i];
    }
    for(int i = 1 ; i <= 8 ; ++i){
        for(int j = 1 ; j <= 8 ; ++j){
            if(arr[i][j] == 'W'){
                bool b = 1;
                for(int k = 1 ; k < i ; ++k){
                    if(arr[k][j] != '.'){
                        b = 0;
                        break;
                    }
                }
                if(b){
                    ans1 = min(ans1 , i - 1);
                }
            }
            else if(arr[i][j] == 'B'){
                bool b = 1;
                for(int k = 8 ; k > i ; --k){
                    if(arr[k][j] != '.'){
                        b = 0;
                        break;
                    }
                }
                if(b){
                    ans2 = min(ans2 , 8 - i);
                }
            }
        }
    }
    cout << ((ans1 <= ans2) ? 'A' : 'B');
}
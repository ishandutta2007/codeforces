#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
string arr[N];
bool x = 0 , y = 0;
int row[N];
int column[N];
int main(){
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> arr[i];
        row[i] = -1;
        column[i] = -1;
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(arr[i][j] == '.'){
                row[i] = j;
                column[j] = i;
            }
        }
    }
    for(int i = 0 ; i < n ; ++i){
        if(row[i] == -1){
            x = 1;
        }
        if(column[i] == -1){
            y = 1;
        }
    }
    if(x & y){
        cout << -1;
    }
    else if(x){
        for(int i = 0 ; i < n ; ++i){
            cout << column[i] + 1 << " " << i + 1 << "\n";
        }
    }
    else{
        for(int i = 0 ; i < n ; ++i){
            cout << i + 1 << " " << row[i] + 1 << "\n";
        }
    }
}
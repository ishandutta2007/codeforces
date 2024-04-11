#include "bits/stdc++.h"
using namespace std;
int n;
int k;
int lft;
int oddcnt = 0;
int evencnt;
string arr[2] = {"Daenerys" , "Stannis"};
int main(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> evencnt;
        oddcnt += evencnt & 1;
    }
    evencnt = n - oddcnt;
    lft = n - k;
    if(!lft){
        cout << arr[oddcnt & 1];
    }
    else{
        if((lft >> 1) >= oddcnt){
            cout << arr[0];
        }
        else if((lft >> 1) >= evencnt){
            cout << arr[k & 1];
        }
        else {
            cout <<arr[(n - k) & 1];
        }
    }
}
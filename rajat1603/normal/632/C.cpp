#include "bits/stdc++.h"
using namespace std;
const int N = 5e4 + 4;
int n;
string arr[N];
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    sort(arr + 1 , arr + 1 + n , [](string a , string b){
        return (a + b) < (b + a);
    });
    for(int i = 2 ; i <= n ; ++i){
        arr[1] += arr[i];
    }
    cout << arr[1];
}
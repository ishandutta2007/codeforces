#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int arr[N];
int n;
set < int > s;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        while(arr[i] % 2 == 0){
            arr[i] >>= 1;
        }
        while(arr[i] % 3 == 0){
            arr[i] /= 3;
        }
        s.insert(arr[i]);
    }
    if(s.size() == 1){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}
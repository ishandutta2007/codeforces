#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    sort(arr + 1 , arr + 1 + n);
    for(int i = 1 ; i + 2 <= n ; ++i){
        if(arr[i] + arr[i + 1] > arr[i + 2]){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
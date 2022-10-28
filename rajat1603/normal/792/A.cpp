#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
int val , cnt;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    sort(arr + 1 , arr + 1 + n);
    val = arr[2] - arr[1];
    cnt = 1;
    for(int i = 3 ; i <= n ; ++i){
        int tmp = arr[i] - arr[i - 1];
        if(tmp == val){
            ++cnt;
        }
        else if(tmp < val){
            val = tmp;
            cnt = 1;
        }
    }
    cout << val << " " << cnt << endl;
}
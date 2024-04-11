#include "bits/stdc++.h"
using namespace std;
const int N = 400;
int n;
int arr[N];
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
        cin >> arr[i];
    int start = 1;
    int finish = n;
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i] == 1){
            start = i;
            break;
        }
    }
    for(int i = n ; i >= 1 ; --i){
        if(arr[i] == 1){
            finish = i;
            break;
        }
    }
    if(n == 1){
        cout << arr[1];
        return 0;
    }
    if(start > finish){
        cout << 0;
        return 0;
    }
    int ans = 0;
    int last = start;
    for(int i = start ; i <= finish ; ++i){
        if(arr[i] == 1){
            ++ans;
            if(i - last == 2){
                ++ans;
            }
            last = i;
        }
    }
    cout << ans;
}
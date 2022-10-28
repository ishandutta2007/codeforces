#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
char c[N];
int arr[N];
int cnt[N] = {0};
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> c[i] >> arr[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        if(c[i] == '+'){
            for(int j = i ; j <= n ; ++j){
                if(j > i && arr[j] == arr[i]){
                    break;
                }
                cnt[j]++;
            }
        }
    }
    for(int i = n ; i >= 1 ; --i){
        if(c[i] == '-'){
            bool b = 0;
            for(int j = i - 1 ; j >= 1 ; --j){
                if(arr[j] == arr[i]){
                    b = 1;
                    break;
                }
            }
            if(!b){
                for(int j = i - 1 ; j >= 0 ; --j){
                    ++cnt[j];
                }
            }
        }
    }
    cout << *max_element(cnt + 0 , cnt + 1 + n);
}
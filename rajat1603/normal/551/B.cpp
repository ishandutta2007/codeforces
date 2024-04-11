#include "bits/stdc++.h"
using namespace std;
string arr[3];
int cnt[3][26] = {0};
int main(){
    for(int i = 0 ; i < 3 ; ++i){
        cin >> arr[i];
    }
    for(int i = 0 ; i < 3 ; ++i){
        for(auto it : arr[i]){
            cnt[i][it - 'a']++;
        }
    }
    int mn = 1 << 20;
    for(int i = 0 ; i < 26 ; ++i){
        if(cnt[1][i]){
            mn = min(mn , cnt[0][i] / cnt[1][i]);
        }
    }
    int ans1 = 0 , ans2 = 0;
    for(int i = 0 ; i <= mn ; ++i){
        int temp = 1 << 20;
        for(int j = 0 ; j < 26 ; ++j){
            if(cnt[2][j]){
                temp = min(temp , (cnt[0][j] - cnt[1][j] * i) / cnt[2][j]);
            }
        }
        if(i + temp > ans1 + ans2){
            ans1 = i;
            ans2 = temp;
        }
    }
    for(int i = 0 ; i < 26 ; ++i){
        while(cnt[0][i] - ans1 * cnt[1][i] - ans2 * cnt[2][i]){
            cout << char(i + 'a');
            cnt[0][i]--;
        }
    }
    while(ans1--){
        cout << arr[1];
    }
    while(ans2--){
        cout << arr[2];
    }
}
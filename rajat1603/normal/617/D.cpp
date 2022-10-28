#include "bits/stdc++.h"
using namespace std;
const int N = 5;
int n = 3;
pair < int , int > arr[N];
int main(){
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &arr[i].first , &arr[i].second);
    }
    if(arr[1].first == arr[2].first && arr[2].first == arr[3].first){
        cout << 1;
        return 0;
    }
    if(arr[1].second == arr[2].second && arr[2].second == arr[3].second){
        cout << 1;
        return 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            int k = 6 - i - j;
            if(arr[i].first == arr[j].first && (!(arr[k].second > min(arr[i].second , arr[j].second) && arr[k].second < max(arr[i].second , arr[j].second)))){
                cout << 2;
                return 0;
            }
            if(arr[i].second == arr[j].second && (!(arr[k].first > min(arr[i].first , arr[j].first) && arr[k].first < max(arr[i].first , arr[j].first)))){
                cout << 2;
                return 0;
            }
        }
    }
    cout << 3;
}
#include "bits/stdc++.h"
using namespace std;
const int N = 101;
int tim[N];
int n , s;
pair < int , int > arr[N];
int main(){
    cin >> n >> s;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr + 1 , arr + 1 + n);
    tim[n + 1] = 0;
    arr[n + 1].first = s;
    arr[0].first = 0;
    arr[0].second = -1e9;
    for(int i = n ; i >= 0 ; --i){
        tim[i] = max(tim[i + 1] + arr[i + 1].first - arr[i].first , arr[i].second);
    }
    cout << tim[0];
}
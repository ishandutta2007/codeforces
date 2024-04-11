#include "bits/stdc++.h"
using namespace std;
const int N = 800 * 800;
int cur = 0;
pair < int , pair < int , int > > arr[N];
bool used[N];
int print[N];
int n;
int main(){
    cin >> n;
    for(int i = 2 ; i <= n + n ; ++i){
        for(int j = 1 ; j < i ; ++j){
            cin >> arr[++cur].first;
            arr[cur].second.first = i;
            arr[cur].second.second = j;
        }
    }
    sort(arr + 1 , arr + 1 + cur);
    for(int i = cur ; i >= 1 ; --i){
        if(!used[arr[i].second.first] && !used[arr[i].second.second]){
            used[arr[i].second.first] = 1;
            used[arr[i].second.second] = 1;
            print[arr[i].second.first] = arr[i].second.second;
            print[arr[i].second.second] = arr[i].second.first;
        }
    }
    for(int i = 1 ; i <= n + n ; ++i){
        cout << print[i] << " ";
    }
}
#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
pair < long long , long long > inp[N];
pair < long long , int > arr[N];
set < pair < long long , int > > s;
int ans[N];
long long l , r , x;
int n , m;
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        cin >> inp[i].first >> inp[i].second;
    }
    for(int i = 2 ; i <= n ; ++i){
        arr[i - 1].first = inp[i].second - inp[i - 1].first;
        arr[i - 1].second = i - 1;
    }
    for(int i = 1 ; i <= m ; ++i){
        cin >> x;
        s.insert({x , i});
    }
    sort(arr + 1 , arr + n);
    for(int i = 1 ; i < n ; ++i){
        auto it = s.lower_bound({inp[arr[i].second + 1].first - inp[arr[i].second].second , -1});
        if(it == s.end() || it -> first > arr[i].first){
            cout << "No";
            return 0;
        }
        ans[arr[i].second] = it -> second;
        s.erase(it);
    }
    cout << "Yes\n";
    for(int i = 1 ; i < n ; ++i){
        cout << ans[i] << " ";
    }
}
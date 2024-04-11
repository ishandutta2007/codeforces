#include "bits/stdc++.h"
using namespace std;
priority_queue < pair < int , int > > pq;
map < int , int > m;
vector < vector < int > > ans;
int n;
int input;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> input;
        m[input]++;
    }
    for(auto it : m){
        pq.push(make_pair(it.second , it.first));
    }
    while(pq.size() >= 3){
        vector < int > v(3);
        vector < pair < int , int > > arr(3);
        for(int i = 0 ; i < 3 ; ++i){
            arr[i] = pq.top();
            pq.pop();
            arr[i].first--;
            v[i] = arr[i].second;
        }
        ans.emplace_back(v);
        for(int i = 0 ; i < 3 ; ++i){
            if(arr[i].first){
                pq.push(arr[i]);
            }
        }
    }
    cout << ans.size();
    for(auto it : ans){
        sort(it.begin() , it.end() , greater < int > ());
        cout << "\n";
        for(int x : it){
            cout << x << " ";
        }
    }
}
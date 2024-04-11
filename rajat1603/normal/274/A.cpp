#include "bits/stdc++.h"
using namespace std;
int n , k;
int ans = 0;
int cur;
set<long long> s;
long long node;
int main(){
    cin >> n >> k;
    if(k == 1){
        cout << n;
        return 0;
    }
    while(n--){
        cin >> cur;
        s.insert(cur);
    }
    while(!s.empty()){
        node = *s.begin();
        cur = 0;
        while(s.find(node) != s.end()){
            cur ++;
            s.erase(s.find(node));
            node *= k;
        }
        ans += (cur + 1) >> 1;
    }
    cout << ans;
}
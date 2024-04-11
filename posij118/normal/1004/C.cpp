#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    long long n, cur, ans;
    ans = 0;

    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    multiset<int> any;
    set<int> left;
    set<int> right;
    int diff[n];

    for(int i=n-1; i>=0; i--){
        if(!right.count(a[i])){
            right.insert(a[i]);

        }
         diff[i] = right.size();
    }

    for(int i=0; i<n-1; i++){
        if(!left.count(a[i])){
            left.insert(a[i]);
            ans += diff[i+1];
        }
    }

    cout << ans << endl;


}
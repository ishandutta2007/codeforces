#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[3*n];
    int l[3*n];
    vector<pair<pair<int, bool>, int> > eve; // prior, index, 1-erase, 0-query

    set<int> s;
    for(int i = 0; i<3*n; i++){
        s.insert(-i);
    }

    for(int i = 0; i<n; i++){
        cin >> a[i];
        a[i + n] = a[i];
        a[i + 2*n] = a[i];
        eve.push_back({{2*a[i], 1}, i});
        eve.push_back({{a[i], 0}, i});
        eve.push_back({{2*a[i + n], 1}, i + n});
        eve.push_back({{a[i + n], 0}, i + n});
        eve.push_back({{2*a[i + 2*n], 1}, i + 2*n});
        eve.push_back({{a[i + 2*n], 0}, i + 2*n});
    }

    sort(eve.begin(), eve.end());
    for(auto x: eve){
        if(x.first.second == 0) s.erase(-x.second);

        else{
            auto it = s.lower_bound(-x.second);

            if(it == s.end()) l[x.second] = -1;
            else l[x.second] = -*it;
        }
    }

    s.clear();
    eve.clear();
    for(int i = 0; i<3*n; i++){
        s.insert(i);
        eve.push_back({{l[i], 1}, i});
    }

    for(int i = 0; i<n; i++){
        eve.push_back({{i, 0}, i});
    }

    int ans[n];
    sort(eve.begin(), eve.end());
    for(auto x: eve){
        if(x.first.second == 1) s.erase(x.second);

        else{
            auto it = s.lower_bound(x.second);

            if(it == s.end()) ans[x.second] = -1;
            else ans[x.second] = *it - x.second;
        }
    }

    for(auto x: ans){
        cout << x << " ";
    }



}
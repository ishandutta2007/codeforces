#include <bits/stdc++.h>
using namespace std;

vector<int> p, inv;
vector<pair<int, int> > ans;

void swp(int a, int b){
    ans.push_back({a + 1, b + 1});
    swap(inv[p[a]], inv[p[b]]);
    swap(p[a], p[b]);
}

int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    p.resize(n);
    inv.resize(n);

    for(int i = 0; i<n; i++){
        cin >> p[i];
        p[i]--;
        inv[p[i]] = i;
    }

    vector<int> large_pairs, small_pairs;
    for(int i = 0; i<n/2; i++){
        if(min(p[i], p[i + n/2]) >= n/2) large_pairs.push_back(i);
        if(max(p[i], p[i + n/2]) < n/2) small_pairs.push_back(i);
    }

    for(int i = 0; i<small_pairs.size(); i++){
        if(small_pairs[i] < large_pairs[i]){
            swp(small_pairs[i], large_pairs[i] + n/2);
        }

        else swp(large_pairs[i], small_pairs[i] + n/2);
    }

    for(int i = 0; i<n/2; i++){
        if(p[i] > p[i + n/2]){
            swp(i, i + n/2);
        }
    }

    for(int i = 0; i<n/2; i++){
        int x = inv[i];
        if(inv[i] == i) continue;
        swp(x, x + n/2);
        swp(x + n/2, i);
        swp(x, x + n/2);
    }

    for(int i = n/2 - 1; i>=0; i--){
        int x = inv[i + n/2];
        if(x == i + n/2) continue;
        swp(x, x- n/2);
        swp(x - n/2, n/2 + i);
        swp(x, x - n/2);
    }

    cout << ans.size() << endl;
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

}
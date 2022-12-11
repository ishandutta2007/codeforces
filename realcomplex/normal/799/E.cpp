#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;

#define int ll

const int N = (int)2e5 + 9;
int tt[N];

bool g1[N];
bool g2[N];

signed main(){
    int n, m, k ;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++ ){
        cin >> tt[i];
    }
    int a, x;
    cin >> a;
    for(int i = 0; i < a; i ++ ){
        cin >> x;
        g1[x] = true;
    }
    cin >> a;
    for(int i = 0 ; i < a; i ++ ){
        cin >> x;
        g2[x] = true;
    }
    vector<int> both, p1, p2;
    multiset<int> used, unused;
    for(int i = 1; i <= n; i ++ ){
        if(g1[i] && g2[i]){
            both.push_back(tt[i]);
        }
        else if(g1[i]){
            p1.push_back(tt[i]);
        }
        else if(g2[i]){
            p2.push_back(tt[i]);
        }
        else{
            unused.insert(tt[i]);
        }
    }
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    sort(both.begin(), both.end());
    int sum = 0, ans = (int)1e15 + 9;
    int n1 = 0, n2 = 0;
    for(int i = 0 ; i < p1.size(); i ++ ){
        if(i < k){
            sum += p1[i];
            n1 ++ ;
        }
        else{
            unused.insert(p1[i]);
        }
    }
    for(int i = 0 ; i < p2.size(); i ++ ){
        if(i < k){
            sum += p2[i];
            n2 ++ ;
        }
        else{
            unused.insert(p2[i]);
        }
    }
    int rem = k;
    int should;
    for(int i = 0 ; i <= both.size() ; i ++ ){
        should = m - i - (rem * 2);
        if(should >= 0){
            while(used.size() < should && !unused.empty()){
                auto it = unused.begin();
                sum += *it;
                used.insert(*it);
                unused.erase(it);
            }
            while(used.size() > should){
                auto it = used.end();
                -- it;
                sum -= *it;
                unused.insert(*it);
                used.erase(it);
            }
            while(!used.empty() && !unused.empty()){
                auto i1 = used.end();
                -- i1;
                auto i2 = unused.begin();
                if(*i1 <= *i2){
                    break;
                }
                sum -= *i1;
                sum += *i2;
                used.insert(*i2);
                unused.insert(*i1);

                used.erase(i1);
                unused.erase(i2);

            }
            if(n1 + n2 + i + (int)used.size() == m){
                ans = min(ans, sum);
            }
        }
        if(rem - 1 >= 0 && rem - 1 < p1.size()){
            sum -= p1[rem - 1];
            -- n1;
            unused.insert(p1[rem - 1]);
        }
        if(rem - 1 >= 0 && rem - 1 < p2.size()){
            sum -= p2[rem - 1];
            -- n2;
            unused.insert(p2[rem - 1]);
        }
        rem = max(0ll, rem - 1);
        if(i < both.size()){
            sum += both[i];
        }
    }
    if(ans == (int)1e15 + 9)
        cout << -1;
    else
        cout << ans;
    return 0;
}
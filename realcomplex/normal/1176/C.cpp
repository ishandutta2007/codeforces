#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 50;
vector<int> T[N];

int main(){
    fastIO;
    vector<int> y = {4,8,15,16,23,42};
    int n;
    cin >> n;
    int a;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> a;
        T[a].push_back(i);
    }
    for(int i = 0 ; i < N; i ++ )
        reverse(T[i].begin(), T[i].end());
    int res = 0;
    bool ok = true;
    int id;
    while(ok){
        id = -1;
        for(auto p : y){
            while(!T[p].empty() && T[p].back() <= id){
                T[p].pop_back();
            }
            if(T[p].empty())
                ok = false;
            else{
                id = T[p].back();
                T[p].pop_back();
            }
        }
        if(ok){
            res += 6;
        }
    }
    cout << n - res << "\n";
    return 0;
}
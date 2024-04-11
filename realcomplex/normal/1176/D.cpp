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

const int N = (int)3e6;
const int M = (int)2e5;
bitset<N> ok;
int mn[N];
vector<int> order;
int iord[N];

int main(){
    fastIO;
    for(int i = 0 ; i < N; i ++ )
        mn[i] = 1;
    order.push_back(1);
    for(int i = 2; i < N ; i++ ){
        if(!ok[i]){
            for(int j = 2 * i ; j < N ; j += i){
                ok[j] = 1;
                if(mn[j] == 1)
                    mn[j] = i;
            }
            iord[i] = order.size();
            order.push_back(i);
        }
    }
    int n;
    cin >> n;
    n *= 2;
    multiset<int> t;
    int a;
    for(int i = 1; i <= n ; i ++ ){
        cin >> a;
        t.insert(a);
    }
    int i1;
    while(!t.empty()){
        auto it = t.end();
        --it;
        i1 = *it;
        if(ok[i1] == 0){
            cout << iord[i1] << " ";
            t.erase(it);
            t.erase(t.find(iord[i1]));
        }
        else{
            cout << i1 << " ";
            t.erase(it);
            t.erase(t.find(i1/mn[i1]));
        }
    }
    return 0;
}
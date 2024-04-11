#include "bits/stdc++.h"
using namespace std;
const int N = 1e2 + 2;
int n;
int nxt[N];
bool visited[N];
vector < int > sz;
long long g;
bool rekt;
int main(){
    cin >> n;
    set < int > s;
    s.clear();
    for(int i = 1 ; i <= n ; ++i){
        cin >> nxt[i];
        s.insert(nxt[i]);
        visited[i] = 0;
    }
    if(s.size() < n){
        printf("-1\n");
        return 0;
    }
    sz.clear();
    rekt = 0;
    g = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(!visited[i]){
            int cnt = 0;
            int node = i;
            do{
                visited[node] = 1;
                ++cnt;
                node = nxt[node];
            }while(node != i);
            if(cnt & 1){
                rekt = 1;
            }
            else{
                cnt >>= 1;
            }
            sz.push_back(cnt);
        }
    }
    long long ans = 1;
    for(auto it : sz){
        long long tmp = __gcd(ans , 1LL * it);
        ans /= tmp;
        ans *= it;
    }
    cout << ans << endl;
}
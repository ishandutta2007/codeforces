#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, w;
        cin >> n >> w;
        vector<int> W(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> W[i];
        }
        sort(W.begin(), W.end());
        reverse(W.begin(), W.end());
        priority_queue<int> rem;
        for(auto x : W){
            if(rem.empty() || rem.top() < x){
                rem.push(w);
            }
            int it = rem.top();
            rem.pop();
            it -= x;
            rem.push(it);
        }
        cout << rem.size() << "\n";
    }
    return 0;
}
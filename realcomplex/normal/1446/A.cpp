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
    for(int t = 1; t <= tc; t ++ ){
        int n;
        ll w;
        cin >> n >> w;
        vector<ll> wei(n);
        ll lim = (w+1)/2;
        for(int i = 0; i < n;i ++ ){
            cin >> wei[i];
        }
        bool fin = true;
        for(int i = 0 ; i < n; i ++ ){
            if(wei[i] >= lim && wei[i] <= w){
                cout << "1\n" << (i+1) << "\n";
                fin = false;
                break;
            }
        }
        if(fin){
            ll sum = 0;
            vector<int> ids;
            for(int i = 0 ; i < n; i ++) {
                if(wei[i] <= lim){
                    sum += wei[i];
                    ids.push_back(i+1);
                    if(sum >= lim){
                        cout << ids.size() << "\n";
                        for(auto x : ids)
                            cout << x << " ";
                        fin = false;
                        break;
                    }
                }
            }
            if(fin){
                cout << "-1\n";
            }
        }
    }
    return 0;
}
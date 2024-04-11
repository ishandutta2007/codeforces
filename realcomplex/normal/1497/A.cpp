#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 1; i <= n; i ++ ){
            cin >> a[i-1];
        }
        sort(a.begin(), a.end());
        int las = -1;
        vector<int> pb;
        for(auto x : a){
            if(x == las){
                pb.push_back(x);
            }
            else{
                cout << x << " ";
            }
            las = x;
        }
        for(auto x : pb) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
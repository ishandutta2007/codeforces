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
    for(int t = tc; t >= 1; t -- ){
        int n;
        cin >> n;
        int sum = 0;
        vector<int> a, b, c;
        int x;
        for(int i = 0 ; i < n; i ++ ){
            cin >> x;
            sum += x;
            if(x > 0)
                a.push_back(x);
            else if(x == 0)
                b.push_back(x);
            else
                c.push_back(x);
        }
        if(sum == 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            if(sum > 0){
                for(auto x : a) cout << x << " ";
                for(auto x : c) cout << x << " ";
            }
            else{
                for(auto x : c) cout << x << " ";
                for(auto x : a) cout << x << " ";
            }
            for(auto x : b){
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
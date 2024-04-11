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
        int n;
        cin >> n;
        vector<int> aa(n);
        bool sol = true;
        for(int i = 0 ; i < n; i ++ ){
            cin >> aa[i];
            if(aa[i] < 0) sol = false;
        }
        if(!sol){
            cout << "NO\n";
        }
        else{
            aa.clear();
            cout << "YES\n";
            for(int i = 0 ; i <= 100; i ++ ){
                aa.push_back(i);
            }
            cout << aa.size() << "\n";
            for(auto x : aa)
                cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
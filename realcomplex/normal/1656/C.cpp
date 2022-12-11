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
        bool zero = false;
        bool one = false;
        vector<int> ord;
        int x;
        for(int i = 1; i <= n; i ++ ){
            cin >> x;
            if(x == 0) zero = true;
            if(x == 1) one = true;
            ord.push_back(x);
        }
        sort(ord.begin(), ord.end());
        if(zero && one){
            cout << "No\n";
        }
        else if(zero){
            cout << "Yes\n";
        }
        else if(one){
            bool sol = true;
            for(int i = 1; i < n; i ++ ){
                if(ord[i] - ord[i - 1] == 1) sol = false;
            }
            if(sol)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else{
            cout << "Yes\n";
        }
    }
    return 0;
}
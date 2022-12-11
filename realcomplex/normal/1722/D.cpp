#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        int cur;
        int maxi;
        char f;
        vector<ll> add;
        ll sum = 0;
        for(int i = 0 ; i < n; i ++ ){
            cin >> f;
            if(f == 'L') cur = i;
            else cur = n - i - 1;
            maxi = max(i, n - i - 1);
            add.push_back(maxi - cur);
            sum += cur;
        }
        sort(add.begin(), add.end());
        reverse(add.begin(), add.end());
        for(int k = 0 ; k < n; k ++ ){
            sum += add[k];
            cout << sum << " ";
        }
        cout << "\n";
    }
    return 0;
}
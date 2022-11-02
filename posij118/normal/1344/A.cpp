#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        set<int> s;

        for(int i = 0; i<n; i++){
                int x;
                cin >> x;
            s.insert((((i + x ) % n) + n) % n);
        }

        if(s.size() == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
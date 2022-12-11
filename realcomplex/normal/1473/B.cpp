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
    int q;
    cin >> q;
    for(int t = 1; t <= q; t ++ ){
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        bool valid;
        bool yes = false;
        for(int p = 1; p <= 20 ; p ++ ){
            if((n * p) % m == 0){
                valid = true;
                for(int l = 0 ; l < n * p; l ++ ){
                    if(a[l % n] != b[l % m]){
                        valid = false;
                    }
                }
                if(valid){
                    for(int l = 0 ; l < n * p ; l ++ ){
                        cout << a[l % n];
                    }
                    cout << "\n";
                    yes=true;
                    break;
                }
            }
        }
        if(!yes)
            cout << "-1\n";
    }
    return 0;
}
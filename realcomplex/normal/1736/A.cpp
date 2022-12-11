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
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0 ; i < n; i ++ ) cin >> a[i];
        for(int i = 0 ; i < n; i ++ ) cin >> b[i];
        int f0 = 0;
        int f1 = 0;
        for(int i = 0 ; i < n; i ++ ){
            if(a[i] != b[i]){
                if(a[i] == 0) f0 ++ ;
                else f1 ++ ;
            }
        }
        if(f0 == f1 && f0 == 0){
            cout << "0\n";
        }
        else{
            cout << min(f0 + f1, abs(f0-f1) + 1) << "\n";
        }
    }
    return 0;
}
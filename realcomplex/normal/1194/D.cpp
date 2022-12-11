#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
 
int main(){
    fastIO;
    int testc;
    cin >> testc;
    for(int tt = 0 ;tt < testc; tt ++ ){
        int n, k;
        cin >> n >> k;
        bool fir;
        if(k % 3 == 1){
            n %= 3;
            if(n >= 1)
                fir = true;
            else
                fir = false;
        }
        else{
            n %= (k + 1);
            if(n >= k)
                fir = true;
            else{
                n %= 3;
                if(n >= 1)
                    fir = true;
                else 
                    fir = false;
            }
        }
        if(fir)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    return 0;
}
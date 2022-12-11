#include <iostream>
#include <vector>

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
        vector<int> a(n), b(n);
        for(int i = 0 ; i < n ; i ++ ) cin >> a[i];
        for(int i = 0 ; i < n ; i ++ ) cin >> b[i];
        bool res = true;
        for(int i = 0 ; i < n ; i ++ ){
            if(a[i] > b[i]) res = false;
            else{
                if(a[i] < b[i] && b[i] - b[(i + 1) % n] > 1){
                    res = false;
                }
            }
        }
        if(!res)
            cout << "NO\n";
        else
            cout << "YES\n";
    
    }
    return 0;
}
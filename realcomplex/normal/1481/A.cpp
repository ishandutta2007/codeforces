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
    for(int ti = 1; ti <= tc ; ti ++ ){
        int px, py;
        cin >> px >> py;
        string t;
        cin >> t;
        int nx = 0, ny = 0;
        for(char x : t){
            if(x == 'U' && py > 0) ny ++ ;
            else if(x == 'D' && py < 0) ny ++ ;
            else if(x == 'L' && px < 0) nx ++ ;
            else if(x == 'R' && px > 0) nx ++ ;
        }
        if(nx >= abs(px) && ny >= abs(py)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
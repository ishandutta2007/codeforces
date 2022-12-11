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
    for(int t = 1 ; t <= tc; t ++ ){
        string s;
        cin >> s;
        if(s.size() % 2 == 1){
            cout << "NO\n";
        }
        else{
            if(s[0] == ')' || s[s.size() - 1] == '('){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }
    }
    return 0;
}
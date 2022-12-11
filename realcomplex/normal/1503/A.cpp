#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;

bool validt(vector<char> seq){
    int cnt = 0;
    for(char x : seq){
        if(x == '(') cnt ++ ;
        else cnt -- ;
        if(cnt < 0) return false;
    }
    if(cnt != 0) return false;
    return true;
}

void solve(){
    int n;
    cin >> n;
    char b;
    int f;
    int x = 0, y = 0;
    vector<char> sa, sb;
    vector<int> pos;
    bool valid = true;
    for(int i = 1; i<= n; i ++ ){
        cin >> b;
        f = b - '0';
        if(f == 0){
            if(x <= y){
                y --;
                x ++ ;
                sa.push_back('(');
                sb.push_back(')');
            }
            else{
                y ++ ;
                x -- ;
                sa.push_back(')');
                sb.push_back('(');
            }
        }
        else{
            x ++ ;
            y ++ ;
            sa.push_back('(');
            sb.push_back('(');
            pos.push_back(i-1);
        }
        if(x < 0 || y < 0)
            valid = false;
    }
    if(!valid || x != y || x % 2 != 0){
        cout << "NO\n";
        return;
    }
    while(x > 0){
        if(pos.empty()){
            cout << "NO\n";
            return;
        }
        sa[pos.back()] = ')';
        sb[pos.back()] = ')';
        pos.pop_back();
        x -= 2;
    }
    if(!validt(sa) || !validt(sb)){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(char x : sa) cout << x;
    cout << "\n";
    for(auto x : sb) cout << x;
    cout << "\n";

}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}
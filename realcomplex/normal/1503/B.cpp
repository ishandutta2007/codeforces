#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    int n;
    cin >> n;
    vector<pii> sa, sb;
    // put 1 in sa
    // put 2 in sb
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            if((i + j) % 2 == 0)
                sa.push_back(mp(i, j));
            else
                sb.push_back(mp(i, j));
        }
    }
    int col;
    for(int iq = 1; iq <= n * n; iq ++ ){
        cin >> col;
        if(!sa.empty() && col != 1){
            cout << 1 << " " << sa.back().fi << " " << sa.back().se << endl;
            fflush(stdout);
            sa.pop_back();
        }
        else if(!sb.empty() && col != 2){
            cout << 2 << " " << sb.back().fi << " " << sb.back().se << endl;
            fflush(stdout);
            sb.pop_back();
        }
        else{
            if(!sa.empty()){
                cout << 3 << " " << sa.back().fi << " " << sa.back().se << endl;
                fflush(stdout);
                sa.pop_back();
            }
            else{
                cout << 3 << " " << sb.back().fi << " " << sb.back().se << endl;
                fflush(stdout);
                sb.pop_back();
            }
        }
    }
    return 0;
}
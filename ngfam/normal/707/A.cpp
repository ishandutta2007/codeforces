#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(false); cout.tie(false);
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const int N = 1e6 + 1, mod = 1e9 + 7;

int n, m; char x;

void MAIN(){
    cin >> n >> m;
    for(int i = 1; i <= n * m; ++i){
        cin >> x;
        if(x == 'C' || x == 'M' || x == 'Y') {
            cout << "#Color";
            return;
        }
    }
    cout << "#Black&White";
}
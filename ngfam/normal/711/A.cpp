#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e3 + 1, mod = 1e9 + 7;

string a[N]; int n, ok;

bool check(char x){
    return (x == 'O');
}

void MAIN(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        if(check(a[i][0]) && check(a[i][1]) && !ok){
             a[i][0] = a[i][1] = '+';
             ok = 1;
        }
        if(check(a[i][3]) && check(a[i][4]) && !ok){
            a[i][3] = a[i][4] = '+';
            ok = 1;
        }
    }
    if(ok){
         cout << "YES\n";
         for(int i = 1; i <= n; ++i) cout << a[i] << "\n";
    }
    else cout << "NO";

}
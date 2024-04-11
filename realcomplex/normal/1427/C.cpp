#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int x[N], y[N], t[N];
int sol[N];

int main(){
    fastIO;
    int r, n;
    cin >> r >> n;
    int mx = -(int)1e9-1;
    int pf = 0;
    t[0]=0,x[0]=1,y[0]=1;
    int outp = 0;
    for(int i = 1; i <= n; i ++ )
        sol[i]=-(int)1e9;
    for(int i =1; i <= n; i ++ ){
        cin >> t[i] >> x[i] >> y[i];
        while(2*r <= t[i]-t[pf]){
            mx=max(mx,sol[pf]);
            pf++;
        }
        sol[i] = mx + 1;
        for(int j = pf; j < i ; j ++ ){
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]){
                sol[i] = max(sol[i], sol[j] + 1);
            }
        }
        outp = max(outp, sol[i]);
    }
    cout << outp << "\n";
    return 0;
}
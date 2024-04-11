#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

int nx[N];
int sw[N];
int suf[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    int a, b;
    int s;
    for(int i = 1; i <= n; i ++ ){
        cin >> a >> b;
        s = (a > b);
        if(a > b) swap(a, b);
        if(!(a <= n && b > n)){
            cout << "-1\n";
            return 0;
        }
        nx[a] = b;
        sw[a] = s;
    }
    for(int i = n; i >= 1; i -- ){
        suf[i]=max(nx[i],suf[i+1]);
    }
    int cum = 0;
    int sz = 0;
    int p1 = 2 * n + 1, p2 = 2 * n + 1;
    int soln = 0;
    for(int i = 1; i <= n; i ++ ){
        if(nx[i] < p1){
            if(p1 > suf[i]){
                soln += min(cum, sz - cum);
                sz = 0;
                cum = 0;
            }
            sz ++ ;
            cum += sw[i];
            p1 = nx[i];
        }
        else{
            if(nx[i] > p2){
                cout << "-1\n";
                return 0;
            }
            sz ++ ;
            p2 = nx[i];
            cum += (sw[i]^1);
        }
        if(i == n){
            soln += min(cum, sz - cum);
        }
    }
    cout << soln << "\n";
    return 0;
}
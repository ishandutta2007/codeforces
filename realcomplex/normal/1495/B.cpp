#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int p[N];
int lef[N], rig[N];
int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> p[i];
    }
    for(int i = 2; i <= n; i ++ ){
        if(p[i] > p[i - 1])
            lef[i] = lef[i-1] + 1;
    }
    for(int i = n-1; i >= 1; i -- ){
        if(p[i] > p[i + 1])
            rig[i] = rig[i+1] + 1;
    }
    int m0 = 0, m1 = 0;
    for(int i = 1; i <= n; i ++ ){
        m0 = max(m0, lef[i]);
        m1 = max(m1, rig[i]);
    }
    int ha = 0, bo = 0;
    if(m0 != m1 || m0 % 2 == 1){
        cout << "0\n";
        return 0;
    }
    for(int i = 1; i <= n; i ++ ){
        if(lef[i] == m0 && rig[i] == m0) ha ++ ;
        if(lef[i] == m0 || rig[i] == m0) bo ++ ;
    }
    if(ha == 1 && bo == 1)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
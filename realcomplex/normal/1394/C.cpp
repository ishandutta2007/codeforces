#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
const int inf = (int)1e9;
int n;
int x[N], y[N];
int sx, sy;

bool can(int xy){
    int L[3], R[3];
    L[0] = L[1] = 0;
    R[0] = R[1] = inf;
    L[2] = -inf;
    R[2] = inf;
    for(int i = 0 ; i < n; i ++ ){
        L[0] = max(L[0], x[i] - xy);
        R[0] = min(R[0], x[i] + xy);
        L[1] = max(L[1], y[i] - xy);
        R[1] = min(R[1], y[i] + xy);
        L[2] = max(L[2], y[i]-x[i] - xy);
        R[2] = min(R[2], y[i]-x[i] + xy);
    }
    if(L[0] > R[0] || L[1] > R[1] || L[2] > R[2]) return false;
    int yy;
    for(int xx = L[0]; xx <= R[0]; xx ++ ){
        yy = 0;
        if(xx == 0) yy = 1;
        yy = max(yy, L[2] + xx);
        yy = max(yy, L[1]);
        if(yy <= R[2] + xx && yy <= R[1]){
            sx = xx;
            sy = yy;
            return true;
        }
    }
    return false;
}

int main(){
    fastIO;
    cin >> n;
    string t;
    for(int i = 0 ; i < n; i ++ ){
        cin >> t;
        for(char c : t){
            if(c == 'B') x[i] ++ ;
            else y[i] ++ ;
        }
    }
    int l = 0, r = (int)5e5 + 10;
    int mid;
    while(l < r){
        mid = (l + r) / 2;
        if(can(mid))
            r = mid;
        else
            l = mid + 1;
    }
    can(l);
    cout << l << "\n";
    for(int i = 0 ; i < sx; i ++ )
        cout << "B";
    for(int i = 0 ; i < sy; i ++ )
        cout << "N";
    cout << "\n";
    return 0;
}
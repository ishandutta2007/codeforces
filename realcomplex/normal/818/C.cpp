#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

int xmin[N];
int ymin[N];
int xmax[N];
int ymax[N];

int main(){
    fastIO;
    int d, n, m;
    cin >> d >> n >> m;
    int x1[d], y1[d], x2[d], y2[d];
    for(int i = 0 ; i < d; i ++ ){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        xmin[min(x1[i], x2[i])] ++ ;
        ymin[min(y1[i], y2[i])] ++ ;
        xmax[max(x1[i], x2[i])] ++ ;
        ymax[max(y1[i], y2[i])] ++ ;
    }
    for(int i = 1; i <= n; i ++ ){
        xmin[i] += xmin[i-1];
    }
    for(int i = 1; i <= m ; i ++ ){
        ymin[i] += ymin[i-1];
    }
    for(int i = n; i >= 1; i -- ){
        xmax[i] += xmax[i + 1];
    }
    for(int i = m ; i >= 1; i -- ){
        ymax[i] += ymax[i + 1];
    }
    int cl[d], cr[d], ct[d], cb[d];
    int hx, lx, hy, ly;
    for(int i = 0 ; i < d; i ++ ){
        hx = max(x1[i], x2[i]);
        lx = min(x1[i], x2[i]);
        hy = max(y1[i], y2[i]);
        ly = min(y1[i], y2[i]);
        cl[i] = xmin[hx-1] - (lx == hx - 1);
        cr[i] = xmax[lx+1] - (hx == lx + 1);
        ct[i] = ymin[hy-1] - (ly == hy - 1);
        cb[i] = ymax[ly+1] - (hy == ly + 1);
    }
    int cntl, cntr, cntt, cntb;
    cin >> cntl >> cntr >> cntt >> cntb;
    for(int i = 0 ; i < d; i ++ ){
        if(cl[i] == cntl && cr[i] == cntr && cntt == ct[i] && cntb == cb[i]){
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
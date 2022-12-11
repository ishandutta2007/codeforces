#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n, m, k;
vector<int> xc, yc;

int findm(int ln, int rn, vector<int> p1, vector<int> p2, vector<int> li, vector<int> ri){
    vector<int>lines;
    lines.push_back(1);
    lines.push_back(ln + 1);
    for(auto x : p1)
        lines.push_back(x);
    for(auto x : p2)
        lines.push_back(x+1);
    sort(lines.begin(), lines.end());
    lines.resize(unique(lines.begin(), lines.end()) - lines.begin());
    int cl, cr;
    int mx;
    for(int i = 1; i < lines.size(); i ++ ){
        cl = lines[i-1];
        cr = lines[i]-1;
        vector<pii> q;
        for(int j = 0 ; j <p1.size() ; j ++ ){
            if(p1[j] <= cl && p2[j] >= cr){
                q.push_back(mp(li[j], ri[j]));
            }
        }
        sort(q.begin(), q.end());
        mx = 0;
        for(auto sg : q){
            if(sg.fi > mx + 1){
                return cl;
            }
            mx = max(mx, sg.se);
        }
        if(mx < rn)
            return cl;
    }
    return -1;
}

bool ok(int t){
    vector<int> y1, y2;
    vector<int> xl, xr;
    for(int i = 0 ; i < k ; i ++ ){
        xl.push_back(max(xc[i] - t, 1));
        xr.push_back(min(xc[i] + t, n));
        y1.push_back(max(yc[i] - t, 1));
        y2.push_back(min(yc[i] + t, m));
    }

    int my = findm(m, n, y1, y2, xl, xr);
    int mx = findm(n, m, xl, xr, y1, y2);
    if(mx == -1 || my == -1)
        return true;
    mx = min(mx + t, n);
    my = min(my + t, m);
    xl.push_back(max(mx - t, 1));
    xr.push_back(min(mx + t, n));
    y1.push_back(max(my - t, 1));
    y2.push_back(min(my + t, m));
    return findm(n, m, xl, xr, y1, y2) == -1;
}

int main(){
    fastIO;
    cin >> n >> m >> k;
    int cx, cy;
    for(int i = 0 ; i < k ; i ++ ){
        cin >> cx >> cy;
        xc.push_back(cx);
        yc.push_back(cy);
    }
    int L = 0, R = max(n, m);
    int M;
    while(L<R){
        M = (L + R) / 2;
        if(ok(M)){
            R = M;
        }
        else{
            L = M + 1;
        }
    }
    cout << R;
    return 0;
}
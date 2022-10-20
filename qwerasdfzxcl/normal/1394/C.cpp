#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
pair<int, int> a[300300];
int n;

int myabs(int x){
    if (x<0) return -x;
    return x;
}

int calc(int x, int y){
    int ret = 0;
    for (int i=0;i<n;i++){
        if (a[i].first<x && a[i].second>y) ret = max(ret, x-a[i].first+a[i].second-y);
        else if (a[i].first>x && a[i].second<y) ret = max(ret, a[i].first-x+y-a[i].second);
        else ret = max(ret, max(myabs(x-a[i].first), myabs(y-a[i].second)));
    }
    return ret;
}

pair<int, int> solve(int r){
    int minx = 0, maxx = 1e9, miny = 0, maxy = 1e9, minxy = -1e9, maxxy = 1e9;
    for (int i=0;i<n;i++){
        minx = max(minx, a[i].first-r);
        maxx = min(maxx, a[i].first+r);
        miny = max(miny, a[i].second-r);
        maxy = min(maxy, a[i].second+r);
        minxy = max(minxy, a[i].first-a[i].second-r);
        maxxy = min(maxxy, a[i].first-a[i].second+r);
    }
    if (minx>maxx || miny>maxy || minxy>maxxy) return {-1, -1};
    if (maxx-miny<minxy || minx-maxy>maxxy) return {-1, -1};

    pair<int, int> candidate[]={
        {minx, miny}, {minx, maxy}, {maxx, miny}, {maxx, maxy},
        {minxy+miny, miny}, {minxy+maxy, maxy}, {minx, minx-minxy}, {maxx, maxx-minxy},
        {maxxy+miny, miny}, {maxxy+maxy, maxy}, {minx, minx-maxxy}, {maxx, maxx-maxxy}
    };
    for (int i=0;i<12;i++){
        int curx = candidate[i].first, cury = candidate[i].second;
        if (minx<=curx && curx<=maxx && miny<=cury && cury<=maxy && minxy<=curx-cury && curx-cury<=maxxy){
            if (curx || cury) return {curx, cury};
        }
    }
    exit(5);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        for (auto &c:tmp){
            if (c=='B') a[i].first++;
            else a[i].second++;
        }
    }
    pair<int, pair<int, int>> tmp;
    int l = 0, r = 500500, ans = -1;
    pair<int, int> rans;
    while(l<r){
        int m = (l+r)>>1;
        auto tmp = solve(m);
        if (tmp.first!=-1) ans = m, r = m, rans = tmp;
        else l = m+1;
    }
    printf("%d\n", ans);
    for (int i=0;i<rans.first;i++) printf("B");
    for (int i=0;i<rans.second;i++) printf("N");

    return 0;
}
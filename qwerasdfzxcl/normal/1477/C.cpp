#include <bits/stdc++.h>
#define x first
#define y second

typedef long long ll;
using namespace std;
pair<int, int> xy[5050];
vector<int> ans;

bool deg(pair<int, int> &p, pair<int, int> &q, pair<int, int> &r){
    ll x1=p.x-q.x, x2 = r.x-q.x, y1=p.y-q.y, y2=r.y-q.y;
    //printf("%lld %lld %lld %lld %lld \n", x1, x2, y1, y2, x1*y1+x2*y2);
    return x1*x2+y1*y2>0;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++) scanf("%d %d", &xy[i].x, &xy[i].y);
    if (deg(xy[1], xy[2], xy[3])){
        ans.push_back(1);
        ans.push_back(2);
        ans.push_back(3);
    }
    else{
        ans.push_back(2);
        ans.push_back(3);
        ans.push_back(1);
        assert(deg(xy[2], xy[3], xy[1]));
    }
    for (int i=4;i<=n;i++){
        int sz = (int)ans.size();
        if (deg(xy[ans[sz-2]], xy[ans[sz-1]], xy[i])){
            ans.push_back(i); continue;
        }
        if (deg(xy[i], xy[ans[0]], xy[ans[1]])){
            ans.insert(ans.begin(), i); continue;
        }
        bool chk=0;
        for (int j=0;j<sz-1;j++){
            if (!deg(xy[ans[j]], xy[i], xy[ans[j+1]])) continue;
            if (!(!j || deg(xy[ans[j-1]], xy[ans[j]], xy[i]))) continue;
            if (!(j==sz-2 || deg(xy[i], xy[ans[j+1]], xy[ans[j+2]]))) continue;
            ans.insert(ans.begin()+j+1, 1, i);
            chk=1; break;
        }
        if (!chk){
            printf("-1\n"); return 0;
        }
    }
    for (auto &x:ans) printf("%d ", x);
    return 0;
}
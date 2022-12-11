#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct E{
    int st;
    int en;
    int len;
};

int main(){
    fastIO;
    int lef, rig;
    cin >> lef >> rig;
    int add = lef - 1;
    vector<E> ee;
    rig -= add;
    if(rig == 1){
        ee.push_back({0, 1, 1});
    }
    else{
        ee.push_back({0, 1, 1});
        ee.push_back({0, 2, 1});
        ee.push_back({1, 2, 1});
        int mx = 2;
        int cur;
        while((1 << mx) <= rig){
            cur = 1;
            ee.push_back({0, mx + 1, 1});
            for(int i = 1; i <= mx; i ++ ){
                ee.push_back({i, mx + 1, cur});
                cur += (1 << (i - 1));
            }
            mx ++ ;
        }
        if(rig > (1 << (mx - 1))){
            ee.push_back({mx, mx + 1, 1});
            ee.push_back({0, mx + 1, 1});
            int cur = (1 << (mx - 1)) + 1;
            for(int i = mx; i >= 1; i -- ){
                if(cur + (1 << (i - 1)) <= rig){
                    ee.push_back({i, mx + 1, cur});
                    cur += (1 << (i - 1));
                }
            }
        }
    }
    int target = 0;
    for(auto q : ee)
        target = max(target, q.en);
    if(add > 0){
        ee.push_back({target, target + 1, add});
        target ++ ;
    }
    cout << "YES\n";
    cout << target + 1 << " " << ee.size() << "\n";
    for(auto q : ee){
        cout << q.st + 1 << " " << q.en + 1 << " " << q.len << "\n";
    }
    return 0;
}
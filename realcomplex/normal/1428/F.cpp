#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 100;

struct Obj{
    int lef;
    int rig;
    int vl;
};

int main(){
    fastIO;
    int n;
    cin >> n;
    char f;
    int cnt = 0;
    vector<Obj> ob;
    ll ans = 0;
    int vl;
    ll pi = 0;
    for(int i = 1; i <= n; i ++ ){
        cin >> f;
        vl = f - '0';
        if(vl == 0){
            for(int j = cnt; j >= 1 ; j -- ){
                ob.push_back({i-j,i-j,j});
            }
            ob.push_back({i, i, 0});
            cnt = 0;
        }
        else{
            cnt ++ ;
            pi += cnt;
            int lef = -1;
            int rig = 0;
            while(!ob.empty() && ob.back().vl <= cnt){
                pi -= ob.back().vl * 1ll * (ob.back().rig - ob.back().lef + 1);
                lef = ob.back().lef;
                if(rig == 0) rig = ob.back().rig;
                ob.pop_back();
            }
            if(rig != 0){
                ob.push_back({lef, rig, cnt});
                pi += (rig-lef+1) * 1ll * cnt;
            }
        }
        ans += pi;
    }
    cout << ans << "\n";
    return 0;
}
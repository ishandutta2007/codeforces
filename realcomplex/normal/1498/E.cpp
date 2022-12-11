#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 510;
int k[N];

struct ord{
    int pi;
    int qi;
    int wei;
    bool operator< (const ord &oo){
        return wei < oo.wei;
    }
};

int main(){
    int n;
    cin >> n;
    vector<pii> aq;
    for(int i = 1; i <= n; i ++ ){
        cin >> k[i];
        aq.push_back(mp(k[i], i));
    }
    sort(aq.begin(), aq.end());
    vector<ord> oo;
    for(int i = 0; i < n; i ++ ){
        for(int j = i + 1; j < n; j ++ ){
            oo.push_back({aq[i].se, aq[j].se, aq[j].fi - aq[i].fi});
        }
    }
    sort(oo.begin(), oo.end());
    reverse(oo.begin(), oo.end());
    for(auto x : oo){
        cout << "? " << x.qi << " " << x.pi << endl;
        fflush(stdout);
        string sol;
        cin >> sol;
        if(sol == "Yes"){
            cout << "! " << x.qi << " " << x.pi << endl;
            return 0;
        }
    }
    cout << "! " << "0 0" << endl;
    return 0;
}
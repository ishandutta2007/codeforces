#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
int cnt[N];
int li[N], ri[N];
int res[N];

int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<pii> segm;
        for(int i = 1; i <= n; i ++ ){
            cin >> li[i] >> ri[i];
            segm.push_back(mp(ri[i] - li[i] + 1, i));
        }
        sort(segm.begin(), segm.end());
        for(int i = 1; i <= n; i ++ ){
            cnt[i] = 0;
        }
        int soln;
        for(auto x : segm){
            soln = -1;
            for(int j = li[x.se]; j <= ri[x.se]; j ++ ){
                if(cnt[j] == 0){
                    soln = j;
                }
            }
            cnt[soln] = 1;
            res[x.se] = soln;
        }
        for(int i = 1; i <= n; i ++ ){
            cout << li[i] << " " << ri[i] << " " << res[i] << "\n";
        }
    }
    return 0;
}
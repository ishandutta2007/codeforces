#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int AL = 26;
vector<int> pos[AL];
int cnt[AL];

int main(){
    fastIO;
    int n;
    cin >> n;
    char let;
    int f;
    for(int i = 0 ;i < AL; i ++ )
        pos[i].push_back(0);
    for(int i = 1; i <= n; i ++ ){
        cin >> let;
        f = let - 'a';
        pos[f].push_back(i);
    }
    int q;
    cin >> q;
    string t;
    int res = 0;
    for(int i = 0 ; i < q; i ++ ){
        cin >> t;
        for(int j = 0 ; j < AL; j ++ )
            cnt[j] = 0;
        for(char p : t)
            cnt[p - 'a'] ++ ;
        res = 0;
        for(int j = 0 ; j < AL; j ++ )
            res = max(res, pos[j][cnt[j]]);
        cout << res << "\n";
    }
    return 0;
}
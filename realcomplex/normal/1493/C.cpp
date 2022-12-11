#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int AL = 26;
int cnt[AL];

int f(int c, int k){
    if(c % k == 0) return 0;
    return k - (c % k);
}

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(n % k != 0){
        cout << "-1\n";
        return;
    }
    for(int i = 0;  i < AL; i ++ )
        cnt[i] = 0;
    int id;
    int ex = 0;
    int mx = -1, ids = -1;
    int pv;
    for(int i = 0 ; i < n; i ++ ){
        id = s[i] - 'a';
        for(int j = id + 1; j < AL; j ++ ){
            pv = ex;
            ex -= f(cnt[j], k);
            cnt[j] ++ ;
            ex += f(cnt[j], k);
            //
            if((i + 1) + ex <= n){
                mx = i;
                ids = j;
                ex = pv;
                cnt[j] -- ;
                break;
            }
            cnt[j] -- ;
            ex = pv;
        }
        ex -= f(cnt[id], k);
        cnt[id] ++ ;
        ex += f(cnt[id], k);
    }
    if(ex == 0){
        cout << s << "\n";
        return;
    }
    for(int i = 0 ; i < AL; i ++ ) cnt[i] = 0;
    for(int i = 0 ; i < mx; i ++ ){
        id = s[i] - 'a';
        cnt[id] ++ ;
    }
    cnt[ids] ++ ;
    string pre;
    for(int i = 0 ; i < mx; i ++ ){
        pre.push_back(s[i]);
    }
    pre.push_back(char(ids + 'a'));
    string en;
    for(int i = 0 ;i < AL; i ++ ){
        while(cnt[i] % k != 0){
            cnt[i] ++ ;
            en.push_back(char(i + 'a'));
        }
    }
    while(pre.size() + en.size() < n){
        for(int i = 0 ; i < k ; i ++ )
            pre.push_back('a');
    }
    cout << pre << en << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}
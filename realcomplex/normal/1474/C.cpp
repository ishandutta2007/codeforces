#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e6 + 100;
int cnt[N];

void solve(){
    int n;
    cin >> n;
    vector<int> a(n*2);
    for(int i = 0 ; i < n * 2; i ++ ){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int tr;
    for(int i = 0 ;i + 1 < n * 2; i ++ ){
        tr=a[i]+a.back();
        for(auto x : a) cnt[x] ++ ;
        vector<pii> lis;
        for(int j = n * 2 - 1; j >= 0 ; j -- ){
            if(cnt[a[j]] == 0) continue;
            if(tr-a[j]==a[j]){
                if(cnt[tr-a[j]] < 2){
                    lis.clear();
                    break;
                }
            }
            else{
                if(cnt[tr-a[j]] == 0){
                    lis.clear();
                    break;
                }
            }
            lis.push_back(mp(a[j],tr-a[j]));
            cnt[a[j]]--;
            cnt[tr-a[j]]--;
            tr=a[j];
        }
        for(auto x : a) cnt[x] = 0;
        if(lis.size() > 0){
            cout << "YES\n";
            cout << a[i]+a.back() << "\n";
            for(auto q : lis){
                cout << q.fi << " " << q.se << "\n";
            }
            return;
        }
    }
    cout << "NO\n";
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
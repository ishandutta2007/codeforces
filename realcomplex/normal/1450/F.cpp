#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
int A[N];
int cnt[N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cnt[i]=0;
    }
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
        cnt[A[i]]++;
    }
    int mx = 0;
    for(int i = 1; i <= n; i ++ ){
        mx=max(mx,cnt[i]);
        cnt[i]=0;
    }
    if(mx > (n+1)/2){
        cout << "-1\n";
        return;
    }
    int li = 1;
    vector<pii> segm;
    int cut = 0;
    for(int i = 1; i <= n; i ++ ){
        if(i > 1 && A[i] == A[i-1]){
            segm.push_back(mp(li,i-1));
            li = i;
            cut ++ ;
        }
    }
    segm.push_back(mp(li,n));
    int cur = 0;
    for(auto x : segm){
        cnt[A[x.fi]]++;
        cnt[A[x.se]]++;
    }
    for(int i = 1; i <= n; i ++ ){
        cur = max(cur, cnt[i]);
    }
    int answ = cut + max(0,cur-(cut+2));
    cout << answ << "\n";
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
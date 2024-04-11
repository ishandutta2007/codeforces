#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

const int maxn = 2e5 + 100;
pie a[maxn], b[maxn];
int ans[2];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    rep(i, n){
        cin >> a[i].p1 >> a[i].p2;
        b[i].p1 = a[i].p2;
        b[i].p2 = a[i].p1;
    }
    sort(a, a + n);
    sort(b, b + n);
    rep(i, n){
        if(a[i].p1 == 0)
            ans[1] = a[i].p2;
        int x = a[i].p1;
        int s = 0, e = n-1;
        while(s < e){
            int mid = (s + e) >> 1;
            if(b[mid].p1 < x)
                s = mid + 1;
            else if(b[mid].p1 > x)
                e = mid - 1;
            else{
                s = mid;
                break;
            }
        }
        if(b[s].p1 != x){
            ans[0] = x;
            cout << x << ' ';
            break;
        }
    }
    cout << ans[1] << ' ';
    for(int i = 2; i < n; i++){
        pie *t = lower_bound(a, a + n, mp(ans[i % 2], 0));
        ans[i % 2] = (*t).p2;
        cout << (*t).p2 << ' ';
    }
    cout << endl;
    return 0;
}
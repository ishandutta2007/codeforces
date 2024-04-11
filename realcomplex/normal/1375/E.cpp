
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
vector<int> Q[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pii> soln;
    vector<int> q;
    vector<bool> use;
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
        q.push_back(a[i]);
        use.push_back(true);
    }
    sort(q.begin(), q.end());
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < q.size(); j ++ ){
            if(use[j] && a[i] == q[j]){
                a[i]=j;
                use[j]=false;
                break;
            }
        }
    }
    for(int i = n - 1; i >= 0 ; i -- ){
        vector<pii> sha;
        for(int j = i - 1; j >= 0; j -- ){
            if(a[j] > a[i]){
                sha.push_back(mp(a[j], j));
            }
        }
        sort(sha.begin(), sha.end());
        for(auto x : sha){
            soln.push_back(mp(x.se, i));
            a[x.se]--;
        }
    }
    cout << soln.size() << "\n";
    for(auto x : soln)
        cout << x.fi + 1 << " " << x.se + 1 << "\n";
    return 0;
}
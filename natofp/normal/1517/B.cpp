#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 105;
multiset<int> a[nax];
int n,m;



void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x; cin >> x;
            a[i].insert(x);
        }
    }
    vector<vector<int> > runners;
    for(int i=1;i<=m;i++){
        vector<int> cur;
        int idx = -1;
        int mini = 2e9;
        for(int i=1;i<=n;i++){
            if((*a[i].begin()) < mini){
                mini = (*a[i].begin());
                idx = i;
            }
        }
        // najmniejszy w idx
        for(int i=1;i<=n;i++){
            if(i != idx){
                int akt = (*a[i].rbegin());
                a[i].erase(a[i].find(akt));
                cur.pb(akt);
            }
            else{
                cur.pb(mini);
                a[idx].erase(a[idx].find(mini));
            }
        }
        runners.pb(cur);
        cur.clear();
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++) cout << runners[j][i - 1] << " ";
        cout << "\n";
    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
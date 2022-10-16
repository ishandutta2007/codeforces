#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long

using namespace std;

vector<pii> ans;
int n;

vector<int> last;
int ile = 0;
void ask(int v){
    ile++;
    assert(ile <= (n + 1) / 2);
    v++;
    cout << "? " << v << endl;
    fflush(stdout);
    vector<int> ans(n, 0);
    for(int i=0;i<n;i++) cin >> ans[i];
    last = ans;
}

void solve(){
    cin >> n;
    ask(0);
    vector<int> p;
    vector<int> np;
    for(int i=0;i<n;i++){
        if(last[i]%2==0) p.pb(i);
        else np.pb(i);
    }

    if(p.size() > np.size()){
        swap(p, np);
    }

    for(int xd : p){
        if(xd != 0) ask(xd);
        for(int i=0;i<n;i++){
            if(last[i] == 1) ans.pb(mp(xd, i));
        }
    }
    cout << "!" << endl;
    fflush(stdout);
    for(pii cur : ans){
        cout << cur.st + 1 << " " << cur.nd + 1 << endl;
        fflush(stdout);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}
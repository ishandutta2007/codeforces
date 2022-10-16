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

vector<int> perm;

int ask(vector<int> c){
    cout << "? ";
    for(int x : c) cout << x << " ";
    cout << endl;
    fflush(stdout);
    int x; cin >> x;
    return x;
}
const int nax = 105;
set<int> mamJuz;
int ans[nax];

void solve(){
    int done = 0;
    int n; cin >> n;
    int curSize = 1;
    int wasBefore = 0;
    vector<int> pozycjeTeraz;
    while(done < n){
        vector<int> que(n, 0);
        int last = n;
        while(mamJuz.count(last) > 0) last -= 1;
        for(int x : mamJuz) que[x - 1] = 1;
        que[last - 1] = 1;
        for(int i=0;i<n;i++){
            if(que[i] == 0){
                que[i] = curSize + 1;
            }
        }
        int k = ask(que);
        done += 1;
        if(k == 0){
            int startFrom = wasBefore + curSize;
            ans[last] = startFrom;
            mamJuz.insert(last);
            startFrom -= 1;
            for(int x : pozycjeTeraz){
                ans[x] = startFrom;
                startFrom -= 1;
                mamJuz.insert(x);
            }
            pozycjeTeraz.clear();
            wasBefore += curSize;
            curSize = 1;
        }
        else{
            pozycjeTeraz.pb(k);
            curSize += 1;
            if(curSize + wasBefore == n){
                int startFrom = wasBefore + curSize;
                ans[last] = startFrom;
                mamJuz.insert(last);
                startFrom -= 1;
                for(int x : pozycjeTeraz){
                    ans[x] = startFrom;
                    startFrom -= 1;
                    mamJuz.insert(x);
                }
                pozycjeTeraz.clear();
                wasBefore += curSize;
                curSize = 1;
                break;
            }
        }
    }
    cout << "! ";
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << endl;
    fflush(stdout);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}
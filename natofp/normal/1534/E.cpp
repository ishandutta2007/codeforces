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
vector<int> last;
int ile = 0;
int n,k;
int ask(vector<int> id){
    cout << "? ";
    for(int x : id) cout << x << " " ;
    cout << endl;
    fflush(stdout);
    int ac; cin >> ac;
    return ac;
}


/*void big(){
    if(n % 2 == k % 2){
        vector<int> one;
        vector<int> two;
        for(int i=1;i<=k;i++) one.pb(i);
        int wsp = (n - k) / 2;
        for(int i=wsp+1;i<=wsp+k;i++) two.pb(i);
        vector<int> tri;

        for(int i=wsp+1;i<=k;i++) tri.pb(i);
        for(int i=wsp+k+1;i<=n;i++) tri.pb(i);
        int ac = ask(one);
        int ac2 = ask(two);
        int ac3 = ask(tri);
        cout << "! " << (ac ^ ac2 ^ ac3) << endl;
        fflush(stdout);
        exit(0);
    }

    // n parzyste , k NIEPARZYSTE




}*/

vector<int> dawaj(int rundy){
    int sumka = rundy * k;
    vector<int> bad = {-1};
    if(sumka < n) return bad;
    vector<int> ans(n, 1);
    sumka -= n;
    if(sumka % 2 != 0) return bad;
    int ma = 1;
    int idx = 0;
    while(sumka > 0){
        sumka -= 2;
        ans[idx] += 2;
        ma = max(ma, ans[idx]);
        idx++;
        idx %= n;
    }
    if(ma > rundy) return bad;
    return ans;
}

void essa(vector<int> ile){
    int ac = 0;
    int sum = 0;
    for(int x : ile) sum += x;
    while(sum > 0){
        set<int> teraz;
        while(teraz.size() < k){
            int ma = 0;
            int id = -1;
            for(int i=0;i<n;i++){
                if(ile[i] > ma && teraz.count(i) == 0){
                    ma = ile[i];
                    id = i;
                }
            }
            teraz.insert(id);
            ile[id]--;
        }
        vector<int> gogo;
        for(int c : teraz) gogo.pb(c + 1);
        ac ^= ask(gogo);
        sum -= k;
    }
    cout << "! " << ac << endl;
    fflush(stdout);
}

void solve(){
    cin >> n >> k;
    if(n % 2 == 1 && k % 2 == 0){
        cout << -1 << endl;
        fflush(stdout);
        return;
    }
    vector<int> wek = {-1};
    vector<int> bad = {-1};
    int c = 0;
    while(wek == bad){
        wek = dawaj(c);
        c++;
    }
    essa(wek);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}
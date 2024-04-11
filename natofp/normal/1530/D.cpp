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

const int nax = 2e5 + 5;
int a[nax];

int cnt[nax];
bool done[nax];
set<int> dostajacy, kupujacy;
int ans[nax];

void solve(){
    int n; cin >> n;
    dostajacy.clear();
    kupujacy.clear();
    for(int i=1;i<=n;i++) cnt[i] = 0;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    for(int i=1;i<=n;i++) done[i] = false;
    for(int i=1;i<=n;i++) ans[i] = 0;
    int ile = 0;
    for(int i=1;i<=n;i++){
        ile += min(cnt[i], 1);
    }
    cout << ile << "\n";
    for(int i=1;i<=n;i++){
        kupujacy.insert(i);
        dostajacy.insert(i);
    }
    for(int i=1;i<=n;i++){
        if(done[a[i]] == false){
            done[a[i]] = true;
            ans[i] = a[i];
            kupujacy.erase(i);
            dostajacy.erase(a[i]);
        }
    }
    if(kupujacy.size() == 1){
        if(*kupujacy.begin() == *dostajacy.begin()){
            int zly = *kupujacy.begin();
            int komu = a[zly];
            int zmiana;
            for(int i=1;i<=n;i++){
                if(ans[i] == komu){
                    zmiana = i;
                }
            }
            ans[zmiana] = zly;
            ans[zly] = a[zly];
        }
        else{
            ans[*kupujacy.begin()] = *dostajacy.begin();
        }
    }
    else if(kupujacy.size() >= 2){
        while(kupujacy.size() > 2){
            int x = (*kupujacy.begin());
            int done;
            for(int y : dostajacy){
                if(x != y){
                    ans[x] = y;
                    done = y;
                    break;
                }
            }
            dostajacy.erase(done);
            kupujacy.erase(x);
        }

        auto it = kupujacy.begin();
        int aa = (*it);
        it++;
        int bb = (*it);
        it = dostajacy.begin();
        int cc = (*it);
        it++;
        int dd = (*it);
        if(aa != cc && bb != dd){
            ans[aa] = cc;
            ans[bb] = dd;
        }
        else{
            ans[aa] = dd;
            ans[bb] = cc;
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
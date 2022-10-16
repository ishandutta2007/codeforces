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

const int nax = 105;
int a[nax * nax];
int n,k;

bool done[nax];
int bonus[nax * nax];

pii color[nax];

void solve(){
    cin >> n >> k;
    for(int i=1;i<=n*k;i++) cin >> a[i];
    int maxi = (n + k - 2) / (k - 1);
    vector<pii> ans;
    for(int i=1;i<=n*k;i++){
        int col = a[i];
        if(done[col] == false){
            int pop = i-1;
            while(pop>0 && a[pop] != col) pop--;
            if(pop == 0) continue;

            bool moge = true;
            for(int j=pop;j<=i;j++){
                if(bonus[j] == maxi) moge = false;
            }
            if(moge){
                for(int j=pop;j<=i;j++){
                    bonus[j]++;
                }
                color[col] = mp(pop, i);
                done[col] = true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << color[i].st << " " << color[i].nd << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while(tt--) solve();

    return 0;
}
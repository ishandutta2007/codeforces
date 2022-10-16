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

const int nax = 55;

char a[nax][nax];

void solve(){
    int n,m; cin >> n >> m;
    set<int> p1;
    set<int> p2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char s; cin >> s;
            if(s == 'R') p1.insert((i + j) % 2);
            else if(s == 'W') p2.insert((i + j) % 2);
            a[i][j] = s;
        }
    }
    if(p1.size() > 1 || p2.size() > 1){
        cout << "NO" << "\n";
        return;
    }
    if(p1.size() == 1 && p2.size() == 1){
        int x = (*p1.begin());
        int y = (*p2.begin());
        if(x == y){
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
    if(p1.size() == 0 && p2.size() == 0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((i + j) % 2 == 0) cout << "R";
                else cout << "W";
            }
            cout << "\n";
        }
    }
    else{
        int r,w;
        if(p1.size()){
            r = ((*p1.begin()));
            w = 1 - r;
        }
        else{
            w = ((*p2.begin()));
            r = 1 - w;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((i+j)%2==r) cout<<"R";
                else cout<<"W";
            }
            cout<<"\n";
        }
    }


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
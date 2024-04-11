
#pragma GCC optimization ("O3")

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 666;
ll len[nax][nax];

vector<pair<pii,int> > zap;

ll kraw[nax][nax];
int n,m;
int q;

vector<pii> edges;



vector<pair<int, int> > to[nax];

ll cheap[nax];

bool jest[nax][nax];
int most[nax];
ll inf = 1e18;

void ent(int x){
    fill(most, most + nax, 0);
    fill(cheap, cheap + nax, 0);
    for(int i=0;i<nax;i++) to[i].clear();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // x - > j, j - > i
            if(kraw[x][j] != 0){
                if(kraw[x][j] + len[j][i] > 1e9) continue;
                to[i].pb(mp(kraw[x][j] + len[j][i], j));
            }
        }
        //sort(to[i].begin(), to[i].end());
    }



    for(auto cur : zap){
        ll L = cur.nd;
        int one = cur.st.nd;
        int two = cur.st.st;
        cheap[one] = max(cheap[one], L - len[x][two]);
        //cheap[two] = max(cheap[two], L - len[x][one]);
    }

    //cheap[i] - NAJMNIEJSZY KOSZT PRZED PRZEJSCIEM KLUCZOWEJ KRAWEDZI JESLI CHCEMY KONCZYC W I

    /*if(dbg){
        for(int i=1;i<=n;i++){
            cout<<"WA"<<i<<" "<<cheap[i]<<endl;
        }
    }*/
    //bool dbg = (x == 2);


    for(int i=1;i<=n;i++){
        for(pii cur : to[i]){
            int y = cur.nd;
            if(cheap[i] >= cur.st){
                jest[x][y] = true;
                jest[y][x] = true;
            }
        }
    }

    //if(dbg) cout<<"ELUWA"<<most[3]<<endl;

   // if(dbg){
   //     cout<<"KURWA"<<most[1]<<endl;
   //     for(pii cur : to[1]){
    //        cout<<"SADSAD"<<cur.st<<" "<<cur.nd<<endl;
    //    }
   // }



}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z; cin>>x>>y>>z;
        kraw[x][y] = z;
        kraw[y][x] = z;
        edges.pb(mp(x, y));
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        int x,y,l; cin>>x>>y>>l;
        zap.pb(mp(mp(x,y),l));

    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) len[i][j] = 0;
            else if(kraw[i][j] != 0) len[i][j] = kraw[i][j];
            else len[i][j] = inf;
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                len[i][j] = min(len[i][j], len[i][k] + len[k][j]);
            }
        }
    }


    for(int i=1;i<=n;i++) ent(i);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(jest[i][j]){
                ans++;
                //cout<<"WTF"<<i<<" "<<j<<endl;
            }
        }
    }
    cout<<ans/2<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
   // cin >> tt;
    while(tt--) solve();

    return 0;
}
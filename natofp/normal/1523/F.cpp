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

int min_time[nax][1 << 14];
int max_done[nax][1 << 14];
int min_dist[14][1 << 14];

int n,m;
int x[15];
int y[15];
vector<pair<int, pii> > quests;


int done[1 << 14];
int LO[1 << 14];
int HI[1 << 14];

void propagate(int nxt){
    for(int mask=1;mask<(1<<n);mask++){
        LO[mask] = done[mask];
        int wsk = done[mask];
        while(wsk < m && min_time[wsk][mask] < nxt){
            for(int c=0;c<n;c++){
                if(!(mask & (1 << c))){
                    min_time[wsk][mask ^ (1 << c)] = min(min_time[wsk][mask ^ (1 << c)], min_time[wsk][mask] + min_dist[c][mask]);
                }
            }
            wsk++;
        }
        done[mask] = wsk;
        HI[mask] = wsk - 1;
    }

    /*for(int i=0;i<m;i++){
        for(int j=1;j<(1<<n);j++){
            for(int c=0;c<n;c++){
                if(!(j & (1 << c))){
                    min_time[i][j ^ (1 << c)] = min(min_time[i][j ^ (1 << c)], min_time[i][j] + min_dist[c][j]);
                }
            }
        }
    }
    */
}

int dist_tow[nax][1 << 14];
int cost[nax][nax];

void solve(){
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> x[i] >> y[i];
    for(int i=0;i<m;i++){
        int xb, yb, t;
        cin >> xb >> yb >> t;
        quests.pb(mp(t, mp(xb, yb)));
    }
    sort(quests.begin(), quests.end());
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            cost[i][j] = abs(quests[i].nd.st - quests[j].nd.st) + abs(quests[i].nd.nd - quests[j].nd.nd);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<(1<<n);j++){
            if(j & (1 << i)) continue;
            int mini = 2e9 + 5;
            for(int k=0;k<n;k++){
                if(j & (1 << k)){
                    mini = min(mini, abs(x[k] - x[i]) + abs(y[k] - y[i]));
                }
            }
            min_dist[i][j] = mini;
        }
    }
    for(int i=0;i<nax;i++){
        for(int j=0;j<(1<<14);j++){
            min_time[i][j] = 2e9;
            max_done[i][j] = -2e9;
        }
    }

    for(int i=0;i<m;i++){
        max_done[i][0] = 1;
    }
    for(int i=0;i<n;i++){
        min_time[0][1 << i] = 0;
    }

    for(int i=0;i<m;i++){
        int xx = quests[i].nd.st;
        int yy = quests[i].nd.nd;
        for(int j=1;j<(1<<n);j++){
            int mini = 2e9 + 5;
            for(int k=0;k<n;k++){
                if(j & (1 << k)){
                    mini = min(mini, abs(xx - x[k]) + abs(yy - y[k]));
                }
            }
            dist_tow[i][j] = mini;
        }
    }

    int ans = 0;
    for(int i=0;i<m;i++){
        // situation before i - th quest
        propagate(quests[i].st);
        // propagate dp towers
        //cout << "AC" << min_time[0][63] << endl;
        //
        int ti = quests[i].st;
        for(int j=1;j<(1<<n);j++){
            for(int k=LO[j];k<=HI[j];k++){
                if(min_time[k][j] + dist_tow[i][j] <= ti){
                    max_done[i][j] = max(max_done[i][j], k + 1);
                }
                for(int to=i+1;to<m;to++){
                    if(min_time[k][j] + dist_tow[to][j] <= quests[to].st){
                        max_done[to][j] = max(max_done[to][j], k + 1);
                    }
                }
            }
            ans = max(ans, max_done[i][j]);
        }
        ans = max(ans, max_done[i][0]);
        // update quest_best
        //

        // propagate quest_best (to next_quests and to next_towers)

        for(int j=1;j<(1<<n);j++){
            for(int to=i+1;to<m;to++){
                int dif = quests[to].st - ti;
                if(dif >= cost[i][to]){
                    max_done[to][j] = max(max_done[to][j], max_done[i][j] + 1);
                }
            }
            int ok = max_done[i][j];
            if(ok < 0) continue;
            for(int c=0;c<n;c++){
                if(!(j & (1 << c))){
                    int di = abs(quests[i].nd.st - x[c]) + abs(quests[i].nd.nd - y[c]);
                    di = min(di, min_dist[c][j]);
                    min_time[ok][j ^ (1 << c)] = min(min_time[ok][j ^ (1 << c)], ti + di);
                }
            }
            min_time[ok][j] = min(min_time[ok][j], ti);
        }
        int j = 0;
        for(int to=i+1;to<m;to++){
            int dif = quests[to].st - ti;
            if(dif >= cost[i][to]){
                max_done[to][j] = max(max_done[to][j], max_done[i][j] + 1);
            }
        }
        int ok = max_done[i][j];
        if(ok < 0) continue;
        for(int c=0;c<n;c++){
            if(!(j & (1 << c))){
                int di = abs(quests[i].nd.st - x[c]) + abs(quests[i].nd.nd - y[c]);
                min_time[ok][j ^ (1 << c)] = min(min_time[ok][j ^ (1 << c)], ti + di);
            }
        }
    }

    cout << ans << "\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();

    return 0;
}
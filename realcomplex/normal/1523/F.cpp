#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll inf = (int)4e9;
const int N = 14;
const int M = 101;
ll xa[N], ya[N];

struct quest{
    ll xx;
    ll yy;
    ll tim;
    bool operator< (const quest &qq) const {
        return tim < qq.tim;
    }
};

vector<quest> lis;

ll turret[1<<N][M]; // = minimum time
ll ques[1<<N][M]; // = maximum answer

ll dist[1<<N][N];
ll tdis[1<<N][M];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n; i ++ ){
        cin >> xa[i] >> ya[i];
    }
    quest cur;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> cur.xx >> cur.yy >> cur.tim;
        lis.push_back(cur);
    }
    sort(lis.begin(), lis.end());

    for(int i = 0 ; i < (1 << n); i ++ ){
        for(int nx = 0; nx < n; nx ++ ){
            if((i & (1 << nx))) continue;
            dist[i][nx] = inf;
            for(int chk = 0 ; chk < n; chk ++ ){
                if(i & (1 << chk)){
                    dist[i][nx] = min(dist[i][nx], abs(xa[nx]-xa[chk])+abs(ya[nx]-ya[chk]));
                }
            }
        }
    }
    for(int i = 0 ; i < (1 << n); i ++ ){
        for(int nx = 0; nx < m; nx ++ ){
            tdis[i][nx]=inf;
            for(int chk = 0; chk < n; chk ++ ){
                if((i & (1 << chk))) {
                    tdis[i][nx] = min(tdis[i][nx], abs(lis[nx].xx - xa[chk]) + abs(lis[nx].yy - ya[chk]));
                }
            }
        }
    }

    for(int i = 0 ; i < (1 << n); i ++ ){
        for(int j = 0 ; j <= m ; j ++ ){
            turret[i][j] = inf;
        }
    }
    for(int i = 0 ; i < (1 << n); i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            ques[i][j] = 0;
        }
    }



    for(int i = 0 ; i < n; i ++ ){
        turret[(1 << i)][0] = 0;
    }
    for(int i = 0 ; i < m; i ++ ){
        ques[0][i] = 1;
    }
    int i1, i2;
    ll sol = 0;
    int nmask;
    int ele;
    for(int mask = 0 ; mask < (1 << n); mask ++ ){
        i1 = 0;
        i2 = 0;
        while(i1 <= m || i2 < m){
            if(i1 <= m && (i2 >= m || turret[mask][i1] < lis[i2].tim)){
                for(int iq = 0; iq < n; iq ++ ){
                    if((mask & (1 << iq))) continue;
                    turret[(mask | (1 << iq))][i1] = min(turret[(mask | (1 << iq))][i1], turret[mask][i1] + dist[mask][iq]);
                }
                for(int iq = 0 ;iq < m ; iq ++ ){
                    if(turret[mask][i1] + tdis[mask][iq] <= lis[iq].tim){
                        ques[mask][iq] = max(ques[mask][iq], (ll)i1 + 1);
                    }
                }
                i1 ++ ;
            }
            else{
                ele = ques[mask][i2];
                if(ele > 0){
                    for(int iq = 0 ; iq < n; iq ++ ){
                        if((mask & (1 << iq))){
                            turret[mask][ele] = min(turret[mask][ele], lis[i2].tim);
                        }
                        else{
                            turret[(mask | (1 << iq))][ele] = min(turret[(mask | (1 << iq))][ele], lis[i2].tim + abs(xa[iq] - lis[i2].xx) + abs(ya[iq] - lis[i2].yy));
                        }
                    }
                    for(int iq = 0; iq < m ; iq ++ ){
                        if(lis[i2].tim + abs(lis[iq].xx - lis[i2].xx) + abs(lis[iq].yy - lis[i2].yy) <= lis[iq].tim){
                            ques[mask][iq] = max(ques[mask][iq], (ll)ele + 1);
                        }
                    }
                    sol = max(sol, (ll)ele);
                }
                i2 ++ ;
            }
        }
    }

    cout << sol << "\n";
    return 0;
}
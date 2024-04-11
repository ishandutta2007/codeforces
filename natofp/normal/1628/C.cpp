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

const int nax = 2005;
int a[nax][nax];
int n;
int c[nax][nax];

bool cmp(pii one, pii two){
    int d1 = one.st + one.nd;
    int d2 = two.st + two.nd;
    if(d1 == d2) return one.st < two.st;
    return d1 < d2;
}

bool cmp2(pii one, pii two){
    int d1 = one.st - one.nd;
    int d2 = two.st - two.nd;
    if(d1 == d2) return one.st < two.st;
    return d1 < d2;
}

bool ok(int r, int c){
    return (r >= 1 && c >= 1 && r <=n && c <= n);
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin >> a[i][j];
    }
    int ans = 0;
    vector<pii> ord1, ord2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i+j)%2==1)ord1.pb(mp(i, j));
            else ord2.pb(mp(i, j));

        }
    }
    sort(ord1.begin(), ord1.end(), cmp);
    sort(ord2.begin(), ord2.end(), cmp2);

    for(int b=0;b<30;b++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                c[i][j] = 0;
            }
        }
        for(pii cur : ord1){
            if(cur.st == 1 || cur.nd == n){
                c[cur.st][cur.nd] = 1;
            }
            else{
                pii who;
                if(cur.st != 1) who = mp(cur.st - 1, cur.nd);
                else who = mp(cur.st, cur.nd - 1);
                int w = ((a[who.st][who.nd] & (1 << b)) > 0);
                int cnt = 0;

                if(ok(who.st - 1, who.nd) && c[who.st - 1][who.nd] == 1) cnt += 1;
                if(ok(who.st + 1, who.nd) && c[who.st + 1][who.nd] == 1) cnt += 1;
                if(ok(who.st, who.nd - 1) && c[who.st][who.nd - 1] == 1) cnt += 1;
                if(ok(who.st , who.nd + 1) && c[who.st][who.nd + 1] == 1) cnt += 1;
                if(cnt % 2 != w % 2) c[cur.st][cur.nd] = 1;
                else c[cur.st][cur.nd] = 0;
            }
        }
        for(pii cur : ord2){
            if(cur.st == 1 || cur.nd == 1){
                c[cur.st][cur.nd] = 1;
            }
            else{
                pii who;
                if(cur.st != 1) who = mp(cur.st - 1, cur.nd);
                else who = mp(cur.st, cur.nd + 1);
                int w = ((a[who.st][who.nd] & (1 << b)) > 0);
                int cnt = 0;

                if(ok(who.st - 1, who.nd) && c[who.st - 1][who.nd] == 1) cnt += 1;
                if(ok(who.st + 1, who.nd) && c[who.st + 1][who.nd] == 1) cnt += 1;
                if(ok(who.st, who.nd - 1) && c[who.st][who.nd - 1] == 1) cnt += 1;
                if(ok(who.st , who.nd + 1) && c[who.st][who.nd + 1] == 1) cnt += 1;
                if(cnt % 2 != w % 2) c[cur.st][cur.nd] = 1;
                else c[cur.st][cur.nd] = 0;
            }
        }
        int x = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                x += c[i][j];
            }
        }
        if(x%2==1) ans += (1 << b);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
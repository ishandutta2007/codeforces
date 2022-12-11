#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = (int)1e9 + 7;

int make_two(vector<int> cycs){
    vector<int> c(5);
    for(auto x : cycs){
        c[x]++;
    }
    int soln = 0;
    while(c[4]>1){
        c[1]++;
        c[3]++;
        c[4]--;
        soln ++ ;
    }
    if(c[4] > 0){ // not optimal so doesnt matter
        if(c[2] < 2){
            c[2] += 2;
        }
        else{
            c[1] ++ ;
            c[3] ++ ;
        }
        soln ++ ;
        c[4] = 0;
    }
    while(c[2] < 2 && c[1] >= 2){
        c[2] ++ ;
        c[1] -= 2;
        soln ++ ;
    }
    while(c[2] < 2){
        c[3]--;
        c[1]++;
        c[2]++;
        soln++;
    }
    c[2] -= 2;
    int take = min(c[1],c[2]);
    soln += take;
    c[1] -= take;
    c[2] -= take;
    soln += c[1] - (c[1]/3);
    soln += c[2];
    return soln;
}

int make_four(vector<int> cycs){
    vector<int> c(5);
    for(auto x : cycs){
        c[x]++;
    }
    int soln = 0;
    while(c[4]>1){
        c[4]--;
        c[1]++;
        c[3]++;
        soln++;
    }
    if(c[4]){
        c[4]=0;
    }
    else if(c[1] >= 1 && c[3] >= 1){
        c[1]--;
        c[3]--;
        soln ++ ;
    }
    else{
        while((c[1] < 2 || c[2] < 1) && (c[1] < 4) && (c[1] < 1 || c[3] < 1)){
            c[3]--;
            c[1]++;
            c[2]++;
            soln++;
        }
        if(c[1] >= 1 && c[3] >= 1){
            c[1]--;
            c[3]--;
            soln ++ ;
        }
        else if(c[1] >= 2 && c[2] >= 1){
            c[1]-=2;
            c[2]--;
            soln+=2;
        }
        else{
            c[1]-=4;
            soln+=3;
        }
    }
    int take = min(c[1],c[2]);
    soln += take;
    c[1] -= take;
    c[2] -= take;
    soln += c[1] - (c[1]/3);
    soln += c[2];
    return soln;
}

void solve(){
    int n;
    cin >> n;
    vector<int> p(n);
    vector<bool> vis(n);
    vector<int> cyc;
    for(int i = 0 ; i < n; i ++ ){
        cin >> p[i];
        p[i]--;
    }
    int cur = 0;
    int cnt = 0;
    for(int i = 0 ; i < n; i ++ ){
        if(vis[i]) continue;
        cur=i;
        cnt = 0;
        while(!vis[cur]){
            cnt ++ ;
            vis[cur]=true;
            cur = p[cur];
        }
        cyc.push_back(cnt);
    }
    int answ = 0;
    for(auto &x : cyc){
        while(x >= 5){
            answ ++ ;
            x -= 3;
        }
    }
    vector<int> c(4);
    int wy = 1;
    if(n % 3 == 0){
        for(auto &x : cyc){
            if(x == 4){
                c[1]++;
                c[3]++;
                answ ++ ;
            }
            else{
                c[x]++;
            }
        }
        wy = 1;
        int take = min(c[1],c[2]);
        answ += take;
        c[1] -= take;
        c[2] -= take;
        answ += c[1] - (c[1]/3);
        answ += c[2];
        for(int i = 0 ; i < n/3; i ++ ){
            wy = (wy * 3ll) % MOD;
        }
        cout << wy << " " << answ << "\n";
    }
    else if(n % 3 == 1){
        answ += min(make_two(cyc),make_four(cyc));
        for(int i = 0 ; i < n/3-1;i ++ ){
            wy = (wy * 3ll) % MOD;
        }
        wy = (wy * 4ll) % MOD;
        cout << wy << " " << answ << "\n";
    }
    else{
        vector<int> c(5);
        for(auto x : cyc){
            c[x]++;
        }
        while(c[4] > 1){
            c[1]++;
            c[3]++;
            c[4]--;
            answ++;
        }
        if(c[4]){
            if(c[2] < 1){
                c[4]=0;
                c[2]+=2;
                answ++;
            }
            else{
                c[1]++;
                c[3]++;
                c[4]=0;
                answ++;
            }
        }
        if(c[2] == 0){
            if(c[1] >= 2){
                c[1] -= 2;
                answ ++ ;
            }
            else{
                c[3]--;
                c[1]++;
                c[2]++;
                answ ++ ;
            }
        }
        c[2]--;
        int take = min(c[1],c[2]);
        answ += take;
        c[1] -= take;
        c[2] -= take;
        answ += c[1] - (c[1]/3);
        answ += c[2];
        for(int i = 0 ; i < n/3; i ++ ){
            wy = (wy * 3ll) % MOD;
        }
        wy = (wy * 2ll) % MOD;
        cout << wy << " " << answ << "\n";
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}
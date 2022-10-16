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
#define mt make_tuple

using namespace std;

const int K = 26;
const int inf = 1e9;

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    int queID;
    int exit_link;

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
        queID = -1;
        exit_link = -1;
    }
};

vector<Vertex> t(1);

void add_string(string const& s, int id) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].queID = id;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

int get_exit_link(int v){
    if(t[v].exit_link == -1){
        if(t[v].leaf) t[v].exit_link = v;
        else if(v == 0) t[v].exit_link = 0;
        else t[v].exit_link = get_exit_link(get_link(v));
    }
    return t[v].exit_link;
}

const int nax = 1e5 + 5;
int n;
string s;
string Q[nax];
int cnt[nax];
vector<int> occ[nax];

void solve(){
    cin >> s >> n;
    for(int i=1;i<=n;i++){
        cin >> cnt[i] >> Q[i];
        add_string(Q[i], i);
    }

    int v = 0;
    for(int i=1;i<=(int)s.size();i++){
        char nxt = s[i - 1];
        v = go(v, nxt);
        int tmp = v;
        while(tmp != 0){
            int z = get_exit_link(tmp);
            if(z == 0) break;
            int kt = t[z].queID;
            occ[kt].pb(i);
            tmp = get_link(z);
        }
    }

    for(int i=1;i<=n;i++){
        if((int)occ[i].size() < cnt[i]){
            cout << -1 << "\n";
            continue;
        }
        int ans = inf;
        for(int j=0;j+cnt[i]-1<(int)occ[i].size();j++){
            ans = min(ans, occ[i][j + cnt[i] - 1] - occ[i][j] + (int)Q[i].size());
        }
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}
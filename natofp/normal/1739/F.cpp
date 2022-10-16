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

const int K = 12;

struct Vertex{
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    int value;
    int reachable_profit = 0;
    int dp[1 << 12];
    char last[1 << 12];
    bool bylo[1 << 12];
    Vertex(int p = -1, char ch = '$') : p(p), pch(ch){
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
        fill(begin(dp), end(dp), 0);
        fill(begin(bylo), end(bylo), false);
        reachable_profit = 0;
        value = 0;
    }
};

vector<Vertex> t(1);

void add_string(string const &s, int value){
    int v = 0;
    for(char ch : s){
        int c = ch - 'a';
        if(t[v].next[c] == -1){
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].value += value;
}

int go(int v, char ch);

int get_link(int v){
    if(t[v].link == -1){
        if(v == 0 || t[v].p == 0) t[v].link = 0;
        else t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch){
    int c = ch - 'a';
    if(t[v].go[c] == -1){
        if(t[v].next[c] != -1) t[v].go[c] = t[v].next[c];
        else t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

int calculate_profit(int v){
    if(t[v].reachable_profit > 0) return t[v].reachable_profit;
    return t[v].reachable_profit = t[v].value + (v == 0 ? 0 : calculate_profit(get_link(v)));
}

const int nax = 2005;
int n;
string s[nax];
int value[nax];
string emp = "";

string get_repr(string s){
    char cnt[26];
    fill(begin(cnt), end(cnt), 0);
    deque<char> ans;
    ans.pb(s[0]);
    ans.pb(s[1]);
    set<pair<char, char> > adj;
    adj.insert(mp(min(s[0], s[1]), max(s[0], s[1])));
    for(int i=2;i<(int)s.size();i++){
        char cur = s[i];
        char pop = s[i - 1];
        auto parka = mp(min(cur, pop), max(cur, pop));
        if(adj.count(parka)) continue;
        adj.insert(parka);
        if(ans.front() == pop) ans.push_front(cur);
        else if(ans.back() == pop) ans.push_back(cur);
        else return emp;
    }
    string answer = "";
    while(!ans.empty()){
        answer += ans.front();
        ans.pop_front();
    }
    for(char x : answer){
        cnt[x - 'a']++;
        if(cnt[x - 'a'] > 1) return emp;
    }
    return answer;
}

int dfs(int v, int mask){
    if(t[v].bylo[mask]) return t[v].dp[mask];
    t[v].bylo[mask] = true;
    t[v].dp[mask] = 0;
    for(int i=0;i<K;i++){
        if(!(mask & (1 << i))){
            int val = dfs(go(v, 'a' + i), mask ^ (1 << i));
            if(val >= t[v].dp[mask]){
                t[v].dp[mask] = val;
                t[v].last[mask] = i;
            }
        }
    }
    t[v].dp[mask] += t[v].reachable_profit;
    return t[v].dp[mask];
}

string odp = "";

void get_ans(int v, int mask){
    if(mask == (1 << K) - 1) return;
    int i = t[v].last[mask];
    odp += ('a' + i);
    get_ans(go(v, 'a' + i), (mask ^ (1 << i)));
}

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> value[i] >> s[i];
    for(int i=1;i<=n;i++) s[i] = get_repr(s[i]);
    for(int i=1;i<=n;i++){
        if(!s[i].empty()){
            add_string(s[i], value[i]);
            auto cur = s[i];
            reverse(cur.begin(), cur.end());
            add_string(cur, value[i]);
        }
    }
    for(int i=0;i<(int)t.size();i++) calculate_profit(i);
    dfs(0, 0);
    get_ans(0, 0);
    cout << odp << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    // cin >> tt;
    while(tt--) solve();

    return 0;
}
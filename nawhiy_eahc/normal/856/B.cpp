#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;
const ll MOD = 1000000009;
const ll PRIME = 100003;
const ll PRIME_MODULO = 161615153;
ll Dict[1000002];

int trieCount;
vector<pair<pair<ll, int>, int> > vec;

int t;
int n;
string str[1000002];
vector<int> childV[1000002];
bool isRoot[1000002];
int ans;

struct Trie{
    int idx, depth, firstLetter = 0;
    Trie* child[26];
    ll hsh;

    Trie(){}
    Trie(int idx, int depth, ll hsh): idx(idx), depth(depth), hsh(hsh){
        for(int i=0; i<26; i++) child[i] = nullptr;
        vec.push_back(make_pair(make_pair(hsh, depth), idx));
    }
    ~Trie(){
        for(int i=0; i<26; i++){
            if(child[i]) delete child[i];
        }
    }

    void makeTrie(string::iterator it, string::iterator itEnd){
        if(it == itEnd) return;
        int c = *it - 'a';
        if(!child[c]){
            child[c] = new Trie(++trieCount, depth+1, (hsh + Dict[depth] * (c+1)) % MOD);
            if(depth == 0) child[c]->firstLetter = c+1;
            else child[c]->firstLetter = firstLetter;
        }
        child[c]->makeTrie(next(it), itEnd);
    }

    void makeEdges(){
        ll tmpHsh = (hsh + MOD - firstLetter) % MOD * PRIME_MODULO % MOD;
        auto it = lower_bound(vec.begin(), vec.end(), make_pair(make_pair(tmpHsh, depth-1), -1));
        if(depth > 1 && it != vec.end() && it->first.first == tmpHsh && it->first.second == depth-1){
            childV[it->second].push_back(idx);
            isRoot[idx] = 0;
//            printf("parent %d / child %d\n", it->second, idx);
        }
        for(int i=0; i<26; i++){
            if(child[i]) child[i]->makeEdges();
        }
    }
};

pair<int, int> dfs(int x){
    int tmp = 1, tmp2 = 0;
    for(auto y: childV[x]){
        auto p = dfs(y);
        tmp += p.second, tmp2 += max(p.first, p.second);
    }
    return make_pair(tmp, tmp2);
}

int main(){
    Dict[0] = 1;
    for(int i=1; i<=1000000; i++) Dict[i] = Dict[i-1] * PRIME % MOD;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        vec.clear();

        cin >> n;
        for(int i=1; i<=n; i++) cin >> str[i];

        trieCount = 0;
        Trie* root = new Trie(++trieCount, 0, 0);
        for(int i=1; i<=n; i++){
            root->makeTrie(str[i].begin(), str[i].end());
        }
        for(int i=1; i<=trieCount; i++){
            childV[i].clear();
            isRoot[i] = 1;
        }
        sort(vec.begin(), vec.end());
        root->makeEdges();

        ans = 0;
        for(int i=2; i<=trieCount; i++){
            if(isRoot[i]){
                auto p = dfs(i);
                ans += max(p.first, p.second);
            }
        }
        printf("%d\n", ans);

        delete root;
    }
}
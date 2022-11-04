#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

const int MAXN = (int) 2e5;

struct Trie {
    Trie *son[2];
    Trie() {
        son[0] = son[1] = NULL;
    }
}*root = new Trie;

void add(Trie *nod, int val, int bit) {
    if(bit >= 0) {
        int r = ((val & (1 << bit)) > 0);
        if(nod -> son[r] == NULL)
            nod -> son[r] = new Trie;
        add(nod -> son[r], val, bit - 1);
    }
}

int a, b;

int check(Trie *nod, int val, int bit, int cur) {
    if(bit == -1)
        return 0;
    else {
        int r = ((val & (1 << bit)) > 0);
        if(r == 0) {
            if(nod -> son[r] != NULL && (cur >= a || (a & (1 << bit)) == 0))
                return check(nod -> son[r], val, bit - 1, cur);
            else
                return check(nod -> son[1 - r], val, bit - 1, cur + (1 << bit)) + (1 << bit);
        }
        else {
            if(nod -> son[r] != NULL && cur + (1 << bit) <= b)
                return check(nod -> son[r], val, bit - 1, cur + (1 << bit));
            else
                return check(nod -> son[1 - r], val, bit - 1, cur) + (1 << bit);
        }
    }
}



vector <int> v;

long long solve(vector <int> v, int bit) {
    int n = v.size();
    if(n <= 1 || bit == -1)
        return 0;
    vector <int> v0, v1;
    for(auto it : v) {
        if(it & (1 << bit))
           v1.push_back(it);
        else
           v0.push_back(it);
    }
    long long ans = 0;
    ans += solve(v0, bit - 1);
    ans += solve(v1, bit - 1);
    int mn = (1 << 30) - 1;
    if(v0.size() == 0 || v1.size() == 0)
        mn = 0;
    else {
        a = (1 << 30);
        b = 0;
        for(auto it : v0) {
            a = min(a, it);
            b = max(b, it);
        }
        for(auto it : v1)
            mn = min(mn, check(root, it, 29, 0));
    }
    return ans + mn;
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x;
        v.push_back(x);
        add(root, x, 29);
    }
    cout << solve(v, 29);
    //cin.close();
    //cout.close();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define pb push_back

struct Node {
    Node* nex[26];
    bool win1, win2;
};

int n, k;
string s;

Node* root;

void add(string s) {
    Node* cur = root;
    for (char c: s) {
        int ind = c - 'a';
        if (cur -> nex[ind] == NULL) cur -> nex[ind] = new Node();
        cur = cur -> nex[ind];
    }
}

void solve(Node* x) {
    x -> win1 = false;
    x -> win2 = true;
    REP (i, 26) if (x -> nex[i] != NULL) {
        solve(x -> nex[i]);
        x -> win2 = false;
    }
    REP (i, 26) if ( x -> nex[i] != NULL) {
        if (! x -> nex[i] -> win1) x -> win1 = true;
        if (! x -> nex[i] -> win2) x -> win2 = true;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> k;
    root = new Node();
    while (n--) {
        cin >> s;
        add(s);
    }
    solve(root);
    // cout << (root -> win1) << (root -> win2) << endl;
    if (root -> win1) {
        if (root -> win2 || k & 1) cout << "First";
        else cout << "Second";
    } else {
        cout << "Second";
    }
}
#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

struct Trie {
    Trie * son[2];
    int sz;
    Trie() {
        memset(son, 0, sizeof(son));
        sz = 0;
    }
};
Trie *T = new Trie;

long long ans = 0;
int k;

void check(Trie *nod, int lg, int val) {
   if(nod == NULL)
       return ;
   if(lg == -1)
       ans += nod -> sz;
   else {
       bool r = ((val & (1 << lg)) > 0);
       if(k & (1 << lg))
           check(nod -> son[1 - r], lg - 1, val);
       else {
           if(nod -> son[1 - r] != NULL)
              ans += nod -> son[1 - r] -> sz;
           check(nod -> son[r], lg - 1, val);
       }
   }
}

void insert(Trie *nod, int lg, int val) {
    nod -> sz++;
    if(lg >= 0) {
        bool r = ((val & (1 << lg)) > 0);
        if(nod -> son[r] == NULL)
            nod -> son[r] = new Trie;
        insert(nod -> son[r], lg - 1, val);
    }
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, a;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int s = 0;
    for(i = 1; i <= n; i++) {
        cin >> a;
        s ^= a;
        if(s >= k)
            ans++;
        check(T, 30, s);
        insert(T, 30, s);
    }
    cout << ans;
   // cin.close();
    //cout.close();
    return 0;
}
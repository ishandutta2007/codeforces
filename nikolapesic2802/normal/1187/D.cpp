#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = (int) 3e5+99;
const int inf = 2e9;
int t, n;
int st[4*N+100];
vector<int> p[N];

int minn(int i, int l, int r, int levi, int desni) {
    if(l>r) return inf;
    if(levi>desni) return inf;
    if(l==levi && r==desni) return st[i];
    int mid = (l+r)/2;
    return min(minn(2*i, l, mid, levi, min(desni, mid)), minn(2*i+1, mid+1, r, max(levi, mid+1), desni));
}
void update(int i, int l, int r, int poz, int vr) {
    if(l == r) {
        st[i] = vr;
        return;
    }
    int mid = (l+r)/2;
    if(poz<=mid) update(2*i, l, mid, poz, vr);
    else update(2*i+1, mid+1, r, poz, vr);
    st[i] = min(st[2*i], st[2*i+1]);
}
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> a, b;
        for(int i=0; i<=n; ++i) p[i].clear();
        for(int i=0; i<4*n; ++i) st[i] = inf;
        for(int i=0; i<n; ++i) {
            int broj; cin >> broj;
            a.push_back(broj);
            p[a[i]].push_back(i);
            update(1,1,n,i+1,a[i]); //Moras sve pozicije updeatovati
        }
        for(int i=0; i<n; ++i) {
            int broj; cin >> broj;
            b.push_back(broj);
        }
        for(int i=0; i<=n; ++i) {
            reverse(p[i].begin(), p[i].end());
        }
        bool moze = true;
        for(int i=0; i<n; ++i) {
            if(p[b[i]].empty()) {moze=false; break;}
            int poss = p[b[i]].back()+1;
            if(minn(1, 1, n, 1, poss) < b[i]) {moze=false; break;}  //Ovde si imao dosta bugova sa poss/ b[i] (mesao si)
            p[b[i]].pop_back();
            update(1, 1, n, poss, inf); //Prekomplikvao si ovo
        }

        cout << (moze ? "YES\n" : "NO\n");
    }
}
/*
1 7
7 4 1 2 5 2 7
7 1 2 4 2 5 7

*/
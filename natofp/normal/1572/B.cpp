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

const int nax = 2e5 + 5;
int a[nax];
int n;


vector<int> ans;

void ope(int id){
    int val = (a[id] ^ a[id + 1] ^ a[id + 2]);
    ans.pb(id);
    for(int i=0;i<3;i++) a[id + i] = val;
}


void no(){
    cout << "NO" << "\n";
}

void yes(){
    cout << "YES" << "\n";
    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
    cout << "\n";
}

void gof(int pos){
    for(int i=pos;i<=n;i++){
        if(a[i] == 0) continue;
        if(a[i + 1] == 1){
            ope(i - 1);
            continue;
        }
        if(a[i + 2] == 1){
            ope(i);
            continue;
        }
        ope(i);
        ope(i - 1);
    }
}

void gob(int pos){
    for(int i=pos;i>=1;i--){
        if(a[i] == 0) continue;
        if(a[i - 1] == 1){
            ope(i - 1);
            continue;
        }
        if(a[i - 2] == 1){
            ope(i - 2);
            continue;
        }
        ope(i - 2);
        ope(i - 1);
    }
}

void solve(){
    ans.clear();
    cin >> n;
    int c = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        c += a[i];
    }
    if(c == n){
        no();
        return;
    }
    if(c & 1){
        no();
        return;
    }
    bool allEven = true;
    int cur = 0;
    int pos = -1;
    for(int i=1;i<=n;i++){
        if(a[i] == 0) cur++;
        else{
            if(cur & 1){
                allEven = false;
                pos = i - 2;
            }
            cur = 0;
        }
    }
    if(a[1] == 0){
        gof(2);
        yes();
        return;
    }
    if(a[n] == 0){
        gob(n - 1);
        yes();
        return;
    }
    int met = 0;
    for(int i=1;i<=n;i++){
        met += a[i];
        if(a[i] == 0 && met % 2 == 0){
            gof(i);
            gob(i);
            yes();
            return;
        }
    }

    if(!allEven){
        while(a[pos] == 0){
            ope(pos);
            pos -= 2;
        }
        ope(pos);
        gof(pos);
        gob(pos);
        yes();
        return;
    }
    no();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
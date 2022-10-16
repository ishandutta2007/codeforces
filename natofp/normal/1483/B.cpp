#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 1e5 + 5;
int a[nax];
int n;
int nxt[nax];
vector<int> ans;
void solve(){
    ans.clear();
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) nxt[i] = (i + 1) % n;
    set<int> coprime;
    for(int i=0;i<n;i++){
        if(__gcd(a[i], a[nxt[i]]) == 1) coprime.insert(i);
    }
    int sz = n;

    if(n == 1){
        if(a[0] == 1){
            cout<<"1 1"<<"\n";
            return;
        }
        else cout<<"0"<<"\n";
        return;
    }

    if(!coprime.size()){
        cout<<"0"<<"\n";
        return;
    }
    int last = -1;
    int pos = (*coprime.lower_bound(0));
    int cur = pos;
    int nex = nxt[cur];
    if(coprime.count(nex)) coprime.erase(nex);
    ans.pb(nex);
    coprime.erase(cur);
    nxt[cur] = nxt[nex];
    if(n > 2 && __gcd(a[cur], a[nxt[cur]]) == 1){
        coprime.insert(cur);
    }
    last = nxt[cur];

    while(!coprime.empty()){
        bool dbg = (ans.size() == 1);
        auto it = (coprime.lower_bound(last));
        if(it == coprime.end()){
            it = coprime.lower_bound(0);
        }
        int cur = (*it);
        int nex = nxt[cur];

        ans.pb(nex);
        coprime.erase(cur);
        if(coprime.count(nex)) coprime.erase(nex);
        nxt[cur] = nxt[nex];
        if(n - ans.size() > 1){
            if(__gcd(a[cur], a[nxt[cur]]) == 1){
                coprime.insert(cur);
            }
        }
        last = nxt[cur];
    }

    if(ans.size() == n - 1){
        set<int> xd;
        for(int i=0;i<n;i++) xd.insert(i);
        for(int x : ans) xd.erase(x);
        if(a[*xd.begin()] == 1) ans.pb(*xd.begin());
    }

    cout<<ans.size()<<" ";
    for(int x : ans) cout<<x + 1<<" ";
    cout<<"\n";



}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--) solve();

    return 0;
}
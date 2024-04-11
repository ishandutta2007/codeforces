#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 3e5 + 5;
int h[nax];
int b[nax];
const int roz = (1<<20);

ll tree[roz][2];
// max, added
ll inf = 1e18;
void add(int lo, int hi,int u, int a,int b, ll val){
    if(lo == a && b == hi){
        tree[u][0] += val;
        tree[u][1] += val;
        return;
    }
    if(b <= a) return;
    int mid = (lo + hi) / 2;
    add(lo, mid, u * 2, a ,min(b,mid), val);
    add(mid, hi, u * 2 + 1,max(a,mid),b,val);
    tree[u][0] = max(tree[u * 2][0], tree[u * 2 + 1][0]) + tree[u][1];
}

ll ask_max(int lo,int hi,int u,int a,int b){
    if(lo == a && b == hi){
        return tree[u][0];
    }
    if(b<=a) return -inf;
    int mid = (lo + hi) / 2;
    ll l = ask_max(lo,mid,u*2,a,min(b,mid));
    ll r = ask_max(mid,hi,u*2+1,max(a,mid),b);
    return max(l, r) + tree[u][1];
}

int n;

ll dp[nax];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin >> h[i];
    for(int i=1;i<=n;i++) cin >> b[i];

    for(int i=0;i<roz/2;i++) add(0,roz/2,1,i,i+1,-inf);
    add(0, roz/2, 1, 0, 1, inf);
    stack<pii> wys; // idx, range (?)
    for(int i=1;i<=n;i++){
        while(!wys.empty()){
            pii top = wys.top();
            if(h[top.st] < h[i]){
                break;
            }
            wys.pop();
            int HI = top.st;
            int LO = top.st - top.nd + 1;
            add(0, roz/2,1,LO-1, HI , -b[top.st]);
        }
        int range = i;
        if(!wys.empty()){
            range = i - wys.top().st;
        }
        wys.push(mp(i, range));
        bool dbg = (i == 2);
        int HI = i;
        int LO = i - range + 1;
        //if(dbg) cout<<"AC"<<LO<<" "<<HI<<endl;
        add(0, roz/2,1,LO-1, HI , b[i]);
        dp[i] = ask_max(0,roz/2,1,0,i);
        add(0,roz/2,1,i,i+1,inf + dp[i]);

    }

    //for(int i=0;i<=n;i++){
    //    cout<<i<<" "<<dp[i]<<endl;
    //}
    cout<<dp[n];

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
   // cin >> tt;
    while(tt--) solve();

    return 0;
}
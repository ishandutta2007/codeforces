#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;


ll n,m,k,T;

struct pt{
    ll x,y;
};

struct mov{
    ll i,r,c;
};

ll mark[4][51] = {0};
vector<mov> moves;

void make_move(pt p1, pt p2){
    ll i = mark[p1.x][p1.y];
    mark[p1.x][p1.y] = -1;
    mark[p2.x][p2.y] = i;
    //cout << i+1 << " " << p2.x+1 << " " << p2.y+1 << "\n";
    moves.push_back({i+1,p2.x+1,p2.y+1});
}

pt nex(pt p){
    if(p.x == 1 && p.y == 0){
        return {2,0};
    }
    if(p.x == 1 && p.y != 0){
        return {1,p.y-1};
    }
    if(p.y == n-1){
        return {1,n-1};
    }
    return {2,p.y+1};
}

void park(){
    for(int c1 = 0; c1 < n; c1++){
        if(mark[1][c1] != -1 && mark[0][c1] == mark[1][c1]){
            make_move({1,c1},{0,c1});
            return;
        }
    }

    for(int c1 = 0; c1 < n; c1++){
        if(mark[2][c1] != -1 && mark[3][c1] == mark[2][c1]){
            make_move({2,c1},{3,c1});
            return;
        }
    }

    for(int c2 = 1; c2 <= 2; c2++){
        for(int c1 = 0; c1 < n; c1++){
            pt p1 = {c2,c1};
            pt p2 = nex(p1);
            if(mark[c2][c1] != -1 && mark[p2.x][p2.y] == -1){
                make_move(p1,p2);
                return;
            }
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;

    cin >> n >> k;


    for(int c1 = 0; c1 < 4; c1++){
        for(int c2 = 0; c2 < n; c2++){
            cin >> a;
            a--;
            mark[c1][c2] = a;
        }
    }

    park();
    if(sz(moves) == 0){
        cout << "-1\n";
    }
    else{
        while(1){
            ll s = sz(moves);
            park();
            if(s == sz(moves))break;
        }
        cout << sz(moves) << "\n";
        for(int c1 = 0; c1 < sz(moves); c1++){
            cout << moves[c1].i << " " << moves[c1].r << " " << moves[c1].c  << "\n";
        }
    }

    return 0;
}
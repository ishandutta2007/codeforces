#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

ll n,m,T,k,d;
const ll big = 1000000007;

vector<string> M;

int DIST[2001][2001] = {0};
bool mark[2001][2001] = {0};

int DX[2] = {0,1};
int DY[2] = {1,0};

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < n;
}

void dijk(){

    queue<ll> Q1;
    queue<ll> Q2;

    Q1.push(0);
    if(M[0][0] == 'a'){
        DIST[0][0] = 1;
    }
    else{
        DIST[0][0] = 2;
    }

    while(!(Q1.empty() && Q2.empty())){
        int a;
        if(!Q1.empty()){
            a = Q1.front();
            Q1.pop();
        }
        else{
            a = Q2.front();
            Q2.pop();
        }
        int ax = a/n;
        int ay = a%n;
        mark[ax][ay] = 1;
        for(int c1 = 0; c1 < 2; c1++){
            int bx = ax+DX[c1];
            int by = ay+DY[c1];
            if(inbounds(bx,by)){
                int b = bx*n+by;

                if(mark[bx][by])continue;
                int d2 = DIST[ax][ay] + (M[bx][by] != 'a');
                if(DIST[bx][by] == 0 || d2 < DIST[bx][by]){
                    DIST[bx][by] = d2;
                    if(M[bx][by] == 'a'){
                        Q1.push(b);
                    }
                    else{
                        Q2.push(b);
                    }
                }
            }
        }

    }

}

bool mark2[2001][2001] = {0};
bool mark3[2001][2001] = {0};

string alfa = "abcdefghijklmnopqrstuvwxyz";

string bfs(){

    string ans = "";
    ans += M[0][0];
    mark2[0][0] = 1;
    for(int c1 = 1; c1 < 2*n-1; c1++){
        int mi = 27;
        for(int c2 = 0; c2 < c1+1; c2++){
            int ax = c2;
            int ay = c1-c2;
            if(inbounds(ax,ay)){

                for(int c3 = 0; c3 < 2; c3++){
                    int bx = ax-DX[c3];
                    int by = ay-DY[c3];
                    if(inbounds(bx,by)){
                        if(mark2[bx][by]){
                            mi = min(mi, M[ax][ay]-'a');
                            mark3[ax][ay] = 1;
                        }
                    }
                }

            }
        }

         for(int c2 = 0; c2 < c1+1; c2++){
            int ax = c2;
            int ay = c1-c2;
            if(inbounds(ax,ay)){

                if(mark3[ax][ay] == 1 && M[ax][ay] == alfa[mi]){
                    mark2[ax][ay] = 1;
                }

            }
        }
        ans += alfa[mi];


    }
    return ans;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> k;
  //  n = 2000;
   // k = 300;
    for(int c1 = 0; c1 < n; c1++){
        string s;
/*
        s = "";
        for(int c2 = 0; c2 < n; c2++){
            s += alfa[rand()%26];
        }
*/
        cin >> s;
        M.push_back(s);
    }
    dijk();
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < n; c2++){
            if(DIST[c1][c2] <= k+1){
                M[c1][c2] = 'a';
            }
        }
    }

    cout << bfs() << "\n";

    return 0;
}
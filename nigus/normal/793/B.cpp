#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll big = 1000000007ll;
ll big2 = 1000000009ll;
ll n,m,q,T,k;



ll M[1001][1001];

ll sx,sy,fx,fy;

bool inbounds(ll x, ll y){
return x >= 0 && x < n && y >= 0 && y < m;
}

bool sweep(ll x, ll y, ll dx, ll dy){
    ll x1,x2;
    x1 = x;
    x2 = y;
    while(inbounds(x1,x2)){

        if(M[x1][x2] == -1)break;
        if(M[x1][x2] == 1)return 1;
        x1 += dx;
        x2 += dy;
    }
    return 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);

    ll a,b,c,d;

    cin >> n >> m;
    string s;
    for(ll c1 = 0; c1 < n; c1++){
        cin >> s;
        for(ll c2 = 0; c2 < m; c2++){
            M[c1][c2] = 0;
            if(s[c2] == 'S'){
                sx = c1;
                sy = c2;
            }
            if(s[c2] == 'T'){
                fx = c1;
                fy = c2;
            }
            if(s[c2] == '*'){
                M[c1][c2] = -1;
            }
        }
    }

    ll dx,dy;
    ll x,y;

    dx = 1;
    dy = 0;
    x = sx;
    y = sy;
    while(inbounds(x,y)){
        if(M[x][y] == -1)break;
        M[x][y] = 1;
        x += dx;
        y += dy;
    }

    dx = -1;
    dy = 0;
    x = sx;
    y = sy;
    while(inbounds(x,y)){
        if(M[x][y] == -1)break;
        M[x][y] = 1;
        x += dx;
        y += dy;
    }

    dx = 0;
    dy = 1;
    x = sx;
    y = sy;
    while(inbounds(x,y)){
        if(M[x][y] == -1)break;
        M[x][y] = 1;
        x += dx;
        y += dy;
    }

    dx = 0;
    dy = -1;
    x = sx;
    y = sy;
    while(inbounds(x,y)){
        if(M[x][y] == -1)break;
        M[x][y] = 1;
        x += dx;
        y += dy;
    }

    bool ans = 0;

    dx = 1;
    dy = 0;
    x = fx;
    y = fy;
    while(inbounds(x,y)){
        if(M[x][y] == -1)break;
        ans |= sweep(x,y,0,1);
        ans |= sweep(x,y,0,-1);
        x += dx;
        y += dy;
    }

    dx = -1;
    dy = 0;
    x = fx;
    y = fy;
    while(inbounds(x,y)){
        if(M[x][y] == -1)break;
        ans |= sweep(x,y,0,1);
        ans |= sweep(x,y,0,-1);
        x += dx;
        y += dy;
    }

    dx = 0;
    dy = 1;
    x = fx;
    y = fy;
    while(inbounds(x,y)){
        if(M[x][y] == -1)break;
        ans |= sweep(x,y,1,0);
        ans |= sweep(x,y,-1,0);
        x += dx;
        y += dy;
    }

    dx = 0;
    dy = -1;
    x = fx;
    y = fy;
    while(inbounds(x,y)){
        if(M[x][y] == -1)break;
        ans |= sweep(x,y,1,0);
        ans |= sweep(x,y,-1,0);
        x += dx;
        y += dy;
    }

    if(ans){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}
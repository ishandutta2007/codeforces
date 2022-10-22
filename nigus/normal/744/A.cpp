#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <random>
#include <chrono>
#include <bitset>
#include <fstream>
#include <sstream>

using namespace std;
using namespace std::chrono;

/*
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
*/

typedef long long ll;
typedef long double ld;

ll big = 1000000007ll;
ll n,m,k,r;
ll T;

vector<ll> A;

vector<ll> nodes;
vector<ll> edges;

vector<vector<ll> > C(1001 , vector<ll>());
ll deg[1001] = {0};

ll sumdeg = 0;
ll nnode = 0;

void bfs(ll i){
sumdeg = 0;
nnode = 0;
queue<ll> Q;
Q.push(i);
bool mark[1001] = {0};
mark[i] = 1;

while(!Q.empty()){
    ll a = Q.front();
    Q.pop();
    nnode++;
    sumdeg += deg[a];
    for(ll c1 = 0; c1 < deg[a]; c1++){
        ll b = C[a][c1];
        if(mark[b] == 0){
            mark[b] = 1;
            Q.push(b);
        }
    }
}
}

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int c1,c2,c3,c4,c5,c6;
    ll a,b,c,e;


    cin >> n >> m >> k;

    for(c1 = 0; c1 < k; c1++){
        cin >> a;
        A.push_back(a-1);
    }
    for(c1 = 0; c1 < m; c1++){
        cin >> a >> b;
        a--;
        b--;
        deg[a]++;
        deg[b]++;
        C[a].push_back(b);
        C[b].push_back(a);
    }

    ll manodes = 0;
    ll i = 0;

    ll lonely = n;

    ll ledge = m;

    for(c1 = 0; c1 < k; c1++){
        bfs(A[c1]);
        nodes.push_back(nnode);
        edges.push_back(sumdeg/2);
        lonely -= nnode;
        ledge -= sumdeg/2;
        if(nnode > manodes){
            manodes = nnode;
            i = c1;
        }
    }

    nodes[i] += lonely;

    ll ans = 0;

    for(c1 = 0; c1 < k; c1++){

        ans += (nodes[c1]*(nodes[c1]-1))/2 - edges[c1];

    }
    cout << ans-ledge << "\n";


    return 0;
}
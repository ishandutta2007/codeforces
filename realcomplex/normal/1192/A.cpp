#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)151111;

int dir[8][2] = {{-1,-1},{0,-1},{+1,-1},{+1,0},{+1,+1},{0,+1},{-1,+1},{-1,0}};
int adj[4][2] = {{-1,0},{+1,0},{0,-1},{0,+1}};

set<pii> graf;
map<ll, int> full;
map<pii, int> col;
set<pii> inq;

int ci[N], cj[N];
priority_queue<int> cand;

set<pii> vso;

const int D = (int)2e9 + 7;

ll getid(pii vv){
    vv.fi += (int)1e9 + 3;
    vv.se += (int)1e9 + 3;
    return vv.fi * 1ll * D + vv.se;
}

void check(pii cur){
    vso.insert(cur);
    pii nx;
    for(int q =0 ; q < 8 ; q ++ ){
        nx = mp(cur.fi+dir[q][0],cur.se+dir[q][1]);
        if(!vso.count(nx) && full.count(getid(nx))){
            check(nx);
        }
    }
}

void add_outside(pii cur){
    pii nx;
    col[cur]=0;
    for(int d = 0; d < 4; d ++ ){
        nx = mp(cur.fi+adj[d][0],cur.se+adj[d][1]);
        if(!graf.count(nx)) continue;
        if(full.count(getid(nx))){
            if(inq.count(nx)) continue;
            inq.insert(nx);
            col[nx]=0;
            cand.push(full[getid(nx)]);
        }
        else{
            if(!col.count(nx) || col[nx] > 0){
                add_outside(nx);
            }
        }
    }
}

void fillc(pii cur, int cl){
    pii nx;
    col[cur]=cl;
    for(int d = 0; d < 4; d ++ ){
        nx = mp(cur.fi+adj[d][0],cur.se+adj[d][1]);
        if(!graf.count(nx)) continue;
        if(full.count(getid(nx))) continue;
        if(col.count(nx)) continue;
        fillc(nx,cl);
    }
}

bool is_valid(pii xx){
    vector<int> q;
    pii nx;
    int cnt = 0;
    for(int t = 0; t < 8 ; t ++ ){
        nx = mp(xx.fi + dir[t][0], xx.se + dir[t][1]);
        if(full.count(getid(nx))){
            cnt ++ ;
            q.push_back(-1);
        }
        else{
            q.push_back(col[nx]);
        }
    }
    if(cnt <= 1 || cnt >= 7) return true;
    int pt, qt;
    for(int t = 0 ; t < 8 ; t += 2){ // corner
        pt = (t - 1 + 8) % 8;
        qt = (t + 1) % 8;
        if(q[t] == -1 && q[pt] >= 0 && q[pt] == q[qt]){
            return false;
        }
    }
    if(q[1] >= 0 && q[1] == q[5] && min({q[2],q[3],q[4]}) == -1 && min({q[0],q[6],q[7]}) == -1){
        return false;
    }
    if(q[3] >= 0 && q[3] == q[7] && min({q[0],q[1],q[2]}) == -1 && min({q[4],q[5],q[6]}) == -1){
        return false;
    }
    return true;
}

bool active[N];

int main(){
    fastIO;
    int n, tip;
    cin >> n >> tip;
    pii nx;
    pii low = mp((int)1e9 + 7, (int)1e9 + 7);
    for(int i = 1; i <= n; i ++ ){
        cin >> ci[i] >> cj[i];
        active[i]=true;
        graf.insert(mp(ci[i],cj[i]));
        full[getid(mp(ci[i],cj[i]))]=i;
        for(int j = 0 ;j < 8; j ++ ){
            nx = mp(ci[i]+dir[j][0],cj[i]+dir[j][1]);
            low = min(low, nx);
            graf.insert(nx);
        }
    }
    check(mp(ci[1],cj[1]));
    if(vso.size() != n){
        cout << "NO\n";
        return 0;
    }
    add_outside(low);
    int cnt = 1;
    for(auto v : graf){
        if(full.count(getid(v)) || col.count(v)) continue;
        fillc(v, cnt);
        cnt ++ ;
    }
    int node;
    vector<int> que;
    int hi, wi;
    for(int delet = 0; delet < n; delet ++ ){
        while(!cand.empty()){
            node = cand.top();
            cand.pop();
            if(!active[node]){
                continue;
            }
            if(is_valid(mp(ci[node],cj[node]))){
                active[node]=false;
                que.push_back(node);
                full.erase(getid(mp(ci[node],cj[node])));
                hi = -1;
                for(int i = 0 ; i < 2; i ++ ){
                    wi = -1;
                    for(int j = 0; j < 2; j ++ ){
                        nx = mp(ci[node]+hi,cj[node]+wi);
                        if(full.count(getid(nx)) && col.count(nx) && !inq.count(nx)){
                            inq.insert(nx);
                            cand.push(full[getid(nx)]);
                        }
                        wi *= -1;
                    }
                    hi *= -1;
                }
                add_outside(mp(ci[node],cj[node]));

                break;
            }
            else{
                inq.erase(mp(ci[node],cj[node]));
            }
        }
    }
    cout << "YES\n";
    reverse(que.begin(), que.end());
    for(auto x : que){
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
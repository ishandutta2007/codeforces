#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);

const int N = (int)1e5 + 9;
vector<int>G[N];
int dp[N][2];
int cnt[N];
int state[N];

void init(){
    for(int i = 0;i<N;i++)
        dp[i][0]= -1 ,dp[i][1] = -1;
}

bool findCycle(int u){
    if(state[u]==1)
        return true;
    if(state[u]==2)
        return false;
    state[u]=1;
    for(auto x : G[u])
        if(findCycle(x))
            return true;
    state[u]=2;
    return false;
}

int main(){
    fastIO;
    init();
    int n,m;
    cin >> n >> m;
    int c,y;
    for(int i = 1;i<=n;i++){
        cin >> c;
        while(c--){
            cin >> y;
            G[i].push_back(y);
        }
    }
    int s;
    cin >> s;
    bool cycle = findCycle(s);
    for(int i = 1;i<=n;i++)
        state[i] = 0;
    queue<int>cur;
    cur.push(s);
    int xi;
    dp[s][0]= 0;
    int cha;
    while(!cur.empty()){
        xi = cur.front();
        cur.pop();
        for(auto x : G[xi]){
            if(state[x]==2)
                continue;
            cha = 0;
            if(dp[xi][0]!=-1 and dp[x][1]==-1){
                state[x]++;
                cha ++ ;
                dp[x][1] = xi;
            }
            if(dp[xi][1]!=-1 and dp[x][0]==-1){
                state[x]++;
                cha ++ ;
                dp[x][0] = xi;
            }
            if(cha != 0)
            cur.push(x);
        }
    }
    int ui;
    vector<int>ans;
    for(int i = 1;i<=n;i++){
        if(!G[i].empty() or dp[i][1]==-1)
            continue;
        ui = 1;
        while(i>0){
            ans.push_back(i);
            i = dp[i][ui];
            ui ^= 1;
        }
        reverse(ans.begin(),ans.end());
        cout << "Win\n";
        for(auto x : ans)
            cout << x << " ";
        return 0;
    }
    if(cycle){
        cout << "Draw\n";
        return 0;
    }
    else{
        cout << "Lose";
        return 0;
    }
    return 0;
}
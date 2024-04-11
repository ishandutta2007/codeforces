#include <bits/stdc++.h>

using namespace std;

string p[100001], s[100001];
map<string, int> StoI;
int mt[100001], in[100001];
vector<int> adj[100001];
queue<int> q, ans;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> p[i];
        StoI[p[i]] = i;
    }

    for(int i=1;i<=m;i++){
        cin >> s[i] >> mt[i];
    }

    for(int i=1;i<=m;i++){
        for(int j=0;j<k;j++){
            if(p[mt[i]][j] != '_' && p[mt[i]][j] != s[i][j]){
                cout << "NO";
                return 0;
            }
        }
    }


    for(int i=1;i<=m;i++){
        for(int j=0;j<(1<<k);j++){
            string temp = s[i];
            for(int t=0;t<k;t++){
                if((1<<t) & j) temp[t] = '_';
            }

            int SI = StoI[temp];

            if(SI != 0 && SI != mt[i]){
                adj[mt[i]].push_back(SI);
                in[SI]++;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(in[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int now = q.front(); q.pop();
        for(int i : adj[now]){
            in[i]--;
            if(in[i] == 0) q.push(i);
        }
        ans.push(now);
    }

    if(ans.size() != n) cout << "NO";
    else{
        cout << "YES\n";
        while(!ans.empty()){
            cout << ans.front() << " ";
            ans.pop();
        }
    }
}
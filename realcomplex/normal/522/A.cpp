#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e3;
vector<int>g[MAXN];
int d[MAXN];

string c(string s){
    for(int j = 0;j<s.size();j++){
        if(s[j] < 96){
            s[j]+=32;
        }
    }
    return s;
}

int main()
{
    map<string,int>hsh;
    hsh["polycarp"] = 1;
    int p = 2;
    for(int j = 0;j<MAXN;j++){
        d[j] = -1;
    }
    int n;
    cin >> n;
    d[1] = 0;
    string v1,v2;
    string u;
    int a,b;
    for(int j = 0;j<n;j++){
        cin >> v1 >> u >> v2;
        v1 = c(v1);
        v2 = c(v2);
        if(hsh[v1] == 0){
            hsh[v1] = p;
            p++;
        }
        if(hsh[v2] == 0){
            hsh[v2] = p;
            p++;
        }
        a = hsh[v1];
        b = hsh[v2];
        g[b].push_back(a);
    }
    queue<int>w;
    w.push(1);
    d[1] = 1;
    while(w.size()>0){
        for(int j = 0;j<g[w.front()].size();j++){
            if(d[g[w.front()][j]] == -1){
                d[g[w.front()][j]] = d[w.front()]+1;
                w.push(g[w.front()][j]);
            }
        }
        w.pop();
    }
    int mx = 0;
    for(int j = 0;j<MAXN;j++){
        mx = max(mx,d[j]);
    }
    cout << mx;
    return 0;
}
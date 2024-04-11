#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> P;
vector<P> Query;
vector<vector<int>> adj;
int C[200005];
int D[200005];
bool isPos = true;
int dfs(int c, int p) {
    C[c] = p;
    int sum1 = 0, sum2 = 0;
    for(int n : adj[c]) {
        if(n==p) continue;
        int m = dfs(n, c);
        if(m==1) sum1++;
        else if(m==-1) sum2++;
    }
    int s1, s2;
    int d = adj[c].size();
    if(d%2==0) {
        s1 = d/2;
        s2 = d/2;
    }
    else {
        s1 = d/2+1;
        s2 = d/2;
    }
    if(sum1>s1||sum2>s2) isPos = false;
    int m3 = 0;
    if(sum1==s1) m3 = -1;
    if(sum2==s2) m3 = 1;
    D[c] = m3;
    return m3;
}
int dfs2(int c, int p, int stat) {
    int sum1 = 0, sum2 = 0;
    for(int n : adj[c]) {
        if(n==p) continue;
        if(D[n]==1) sum1++;
        if(D[n]==-1) sum2++;
    }
    if(stat==0) sum2++;
    if(stat==1) sum1++;
    int s1, s2;
    int d = adj[c].size();
    if(d%2==0) {
        s1 = d/2;
        s2 = d/2;
    }
    else {
        s1 = d/2+1;
        s2 = d/2;
    }
    vector<P> Even;
    vector<int> Odd;
    for(int n : adj[c]) {
        if(n==p) continue;
        if(D[n]==1) {
            dfs2(n,c,1);
            Odd.push_back(n);
        }
        else if(D[n]==-1) {
            Even.push_back(P(n,dfs2(n,c,0)));
        }
        else {
            if(sum1<s1) {
                sum1++;
                dfs2(n,c,1);
                Odd.push_back(n);
            }
            else {
                Even.push_back(P(n,dfs2(n,c,0)));
            }
        }
    }
    int osz = (int)Odd.size()-1;
    int esz = (int)Even.size()-1;
    int i;
    //cout << "initing " << c <<' ' << stat << '\n';
    for(i=d;i>=3-stat;i--) {
        if(i%2==0) {
            Query.push_back(P(c,Even[esz].first));
            Query.push_back(P(Even[esz].first,Even[esz].second));
            esz--;
        }
        else {
            Query.push_back(P(c,Odd[osz]));
            osz--;
        }
    }
    //cout << "Retuning\n";
    if(stat==0) {
        return Odd[0];
    }
    else if(stat==1) {
        return -1;
    }
    else return -2;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int i;
        for(i=0;i<N;i++) C[i] = D[i] = 0;
        adj.clear();
        adj.resize(N);
        isPos = true;
        for(i=0;i<N-1;i++) {
            int a, b;
            cin >> a >> b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        dfs(0, -1);
        if(!isPos) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        Query.clear();
        dfs2(0, -1, 2);
        for(i=0;i<Query.size();i++) {
            cout << Query[i].first+1 << ' ' << Query[i].second+1 << '\n';
        }
    }
}
#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, t[c], dist[c];
bool v[c];
vector<int> sz[c];
queue<int> q;
stack<int> kis, nagy;
void add(int a, int b) {
    if (a>b) swap(a, b);
    sz[a].push_back(b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<=n; i++) {
        while(kis.size()>0 && t[i]<=t[kis.top()]) add(kis.top(), i), kis.pop();
        while(nagy.size()>0 && t[i]>=t[nagy.top()]) add(nagy.top(), i), nagy.pop();
        kis.push(i), nagy.push(i);
    }
    while(kis.size()>0) kis.pop();
    while(nagy.size()>0) nagy.pop();
    for (int i=n; i>=1; i--) {
        while(kis.size()>0 && t[i]<=t[kis.top()]) add(kis.top(), i), kis.pop();
        while(nagy.size()>0 && t[i]>=t[nagy.top()]) add(nagy.top(), i), nagy.pop();
        kis.push(i), nagy.push(i);
    }
    q.push(1);
    while(q.size()>0) {
        int id=q.front();
        q.pop();
        if (!v[id]) {
            v[id]=1;
            for (int i=0; i<sz[id].size(); i++) {
                int x=sz[id][i];
                if (!dist[x]) dist[x]=dist[id]+1, q.push(x);
            }
        }
    }
    cout << dist[n] << "\n";
    return 0;
}
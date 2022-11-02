#include <cstdio>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const int NODES = 20 * 360;

void Erase(set<int>&s, int x) {
    auto it = s.find(x);
    if(it != s.end())
        s.erase(it);
}

void TestCase() {
    
    vector<set<int>>adj(NODES);
    
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 360; j++) {
            if(i != 0)
                adj[i * 360 + j].insert((i - 1) * 360 + j);
            if(i != 19)
                adj[i * 360 + j].insert((i + 1) * 360 + j);
            adj[i * 360 + j].insert(i * 360 + ((j + 1) % 360));
            adj[i * 360 + j].insert(i * 360 + ((j - 1 + 360) % 360));
        }
    }
    
    vector<bool>good(360, true);
    
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char c[2]; scanf("%s", c);
        if(c[0] == 'C') {
            int r, a1, a2; scanf("%d%d%d", &r, &a1, &a2);
            if(r == 20) {
                do {
                    a1 = (a1 + 1) % 360;
                    good[a1] = false;
                } while(a1 != a2);
            } else {
                do {
                    a1 = (a1 + 1) % 360;
                    Erase(adj[(r - 1) * 360 + a1], r * 360 + a1);
                    Erase(adj[r * 360 + a1], (r - 1) * 360 + a1);
                } while(a1 != a2);
            }
        } else {
            int r1, r2, a1; scanf("%d%d%d", &r1, &r2, &a1);
            int a2 = (a1 + 1) % 360;
            
            for(int i = r1; i < r2; i++) {
                Erase(adj[i * 360 + a1], i * 360 + a2);
                Erase(adj[i * 360 + a2], i * 360 + a1);
            }
        }
    }
    
    vector<bool>visited(NODES, false);
    queue<int>q;
    for(int i = 0; i < 360; i++) {
        visited[i] = true;
        q.push(i);
    }
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int y : adj[x]) {
            if(!visited[y]) {
                visited[y] = true;
                q.push(y);
            }
        }
    }
    
    bool answer = false;
    for(int i = 0; i < 360; i++) {
        if(visited[19 * 360 + i] && good[i]) {
            answer = true;
        }
    }
    
    printf("%s\n", answer ? "YES" : "NO");
}

int main() {
    int t; scanf("%d", &t);
    while(t--)
        TestCase();
    return 0;
}
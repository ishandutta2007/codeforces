#include <bits/stdc++.h>
using namespace std;

int n, k, u, v;
vector<vector<int>> graph;
vector<int> cal_nodes;
vector<bool> visited;

vector<int> DC(int src) { // [...,...]

    visited[src] = true;

    // Count num path left
    // cal_nodes(u) -> number of paths in subtree at u that goes through u
    // in O(K) for each of the N nodes ---> todo
    // answer = sum of all cal_nodes(u)
    // depth[u][...] = # of path with length ... and root at u, ... <= k 


    /*
        for (int v : graph[src]) {
            if (!visited[v]) {
                vector<int> count_v = cal_nodes(graph, v);

                for (int K = 0; K < k; ++K) {
                    cal_nodes[src] += count_depth[K] * count_v[k - 1 - K]; // = k
                }

                for (int K = 1; K <= k; ++K) {
                    count_depth[K] += count_v[K - 1];
                }
            }
        }
    */ // O(NK)
    // O(H*K) H = maximum height of tree

    // 

    vector<int> depth(k+1);
    depth[0] = 1;

    for (int i : graph[src]) { // i in graph[src]
      if (!visited[i]) {
        vector<int> depth_i = DC(i); // calculate depth[i] (vector[0...K])

        for (int K = 0; K < k; ++K) {
            cal_nodes[src] += depth[K] * depth_i[k - 1 - K];
        }

        // i = 3
        // depth[3][1] = 1; depth[src][0] = 1
        // --> cal_nodes[src] += depth[src][0] * depth[3][1]

        for (int K = 0; K <= k - 1; ++K)
            depth[K + 1] += depth_i[K];

      }
    }

    return depth;

    // M = number of direct children of src
    // naive: O(M^2 * K)
    // AC: O(M*K)
    // Count node O(K)
    // depth[node][K] * depth[node2][k - K]
    /*for (int K = 0; K < k; ++K) {
        // cal # neigh with legth K
        // cal # neigh with length k - K
        
    }*/
  

    // then insert 1 to the beginning of depth[u]

    // we are at node src
    // for each u such that u is children of src
    // we want to find how many nodes v such that distance(u, v) = i (1 <= i <= k)
}

int main() {

    // Read in the tree
    cin >> n >> k;

    graph = vector<vector<int>>(n + 1, vector<int>());
    visited = vector<bool>(n + 1, false);

    cal_nodes = vector<int>(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Divide and conquer
    DC(1);
    int sum = 0;
    for (int i : cal_nodes) {
        sum += i;
    }
    cout << sum << endl; 

	return 0;
}
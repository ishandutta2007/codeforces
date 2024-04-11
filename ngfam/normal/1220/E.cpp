        #include <bits/stdc++.h>
         
        using namespace std;
         
        const int N = 200010;
         
        int n, m;
        int w[N];
        vector < int > g[N];
         
         
        /// tarjan stuff
         
        int nTime;
        int low[N];
        int num[N];
        stack < int > st;
         
        int nComp;
        int in[N];
        int cnt[N];
        long long score[N];
         
        /// tree stuff
         
        set < int > adj[N];
         
        void tarjan(int v, int p) {
          st.push(v);
          low[v] = num[v] = ++nTime;
         
          for(int s : g[v]) if(s != p) {
            if(num[s]) low[v] = min(low[v], num[s]);
            else {
              tarjan(s, v);
              low[v] = min(low[v], low[s]);
            }
          }
         
          if(low[v] >= num[v]) {
            ++nComp;
            while(!st.empty()) {
              int s = st.top();
              st.pop();
              in[s] = nComp;
              ++cnt[nComp];
              score[nComp] += w[s];
              if(s == v) break;
            }
          }
        }
         
        int goback[N];
        long long f[N][2];
         
        /*
          f[v][0] = already stopped somewhere down here
          f[v][1] = needs to go up
        */
         
        void dfs(int v, int p) {
          f[v][0] = score[v];
          if(cnt[v] > 1) f[v][1] = score[v], goback[v] = 1;
          else f[v][1] = 0;
         
          int best = -1, count = 0;
         
          for(int s : adj[v]) if(s != p) {
            dfs(s, v);
            if(goback[s] > 0) ++count, goback[v] = 1;
            if(best == -1 || f[s][0] - f[s][1] > f[best][0] - f[best][1]) {
              best = s;
            }
          }
         
          if(best != -1) {
            for(auto &s : adj[v]) if(s != p) {
              if(s == best) f[v][0] += f[s][0];
              else f[v][0] += f[s][1];
            }
          }
         
          if(count > 0) {
            f[v][1] = score[v];
            for(auto &s : adj[v]) if(s != p) {
              f[v][1] += f[s][1];
            }
          }
         
        }
         
        int main(){
          ios_base::sync_with_stdio(false); cin.tie(NULL);
         
          cin >> n >> m;
         
          for(int i = 1; i <= n; ++i) cin >> w[i];
         
          for(int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
          }
         
          int start; cin >> start;
         
          tarjan(start, -1);
         
          for(int v = 1; v <= n; ++v) {
            for(int s : g[v]) if(in[v] != in[s]){
              adj[in[v]].insert(in[s]);
              adj[in[s]].insert(in[v]);
            }
          }
         
          dfs(in[start], -1);
         
          cout << max(f[in[start]][0], f[in[start]][1]) << endl;
         
          return 0;
        }
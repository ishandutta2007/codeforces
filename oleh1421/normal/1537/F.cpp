#include "bits/stdc++.h"
 using namespace std;

 const int N = 2e5 + 10;
 vector<long long> adj[N];
 long long s[N], n, m;
 bool bipartite()
 {
	 bool bip = true;

	 for(long long i = 0;i < n;i++)
		 s[i] = -1;

	 queue<long long> q;

	 for(long long i = 0;i < n;i++){
		 if(s[i] != -1)continue;

		 q.push(i);
		 s[i] = 0;

		 while(!q.empty()){
			 long long v = q.front();
			 q.pop();

			 for(long long u: adj[v]){
				 if(s[u] == -1){
					 s[u] = s[v] ^ 1;
					 q.push(u);
				 }else bip &= s[u] != s[v];
			 }
		 }
	 }
	 return bip;
 }

 int main()
 {
	 ios_base::sync_with_stdio(0);cin.tie(0);
	 long long T;
	 cin >> T;
	 while(T--)
	 {
		 cin >> n >> m;
		 for(long long i = 0;i < n;i++)
			 adj[i].clear();

		 vector<long long> v(n), t(n);
		long long p1 = 0, p2 = 0;
		 for(long long i = 0;i < n; i++){
			 cin >> v[i];
			 p1 = (p1 + abs(v[i])) % 2;
		 }
		 for (long long i = 0;i < n; i++){
			 cin >> t[i];
			 p2 = (p2 + abs(t[i])) % 2;
		 }

		 for(long long i = 0;i < m;i++){
			 long long a, b;
			 cin >> a >> b;
			 --a, --b;
			 adj[a].push_back(b);
			 adj[b].push_back(a);
		 }
		 
		 if(p1 != p2){
		   cout << "NO\n";
		   continue;
		 }

		 if(bipartite() == false){
			 cout << "YES\n";
		 }else{
			 vector<long long> c(2, 0);

			 for(int i = 0;i < n;i++){
				 c[s[i]] += v[i] - t[i];
			 }

			 if(c[0] == c[1]){
				 cout << "YES\n";
			 }else cout << "NO\n";
		 }
	 }

 }
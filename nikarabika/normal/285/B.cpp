# include <bits/stdc++.h>

using namespace std;

const int maxn=1e6;

int h[maxn];
int ins;
int n,s,t;

vector <int> adj[maxn];
queue <int> q;

bool mark[maxn];

void bfs(int x)
{
	mark[x]=true;
	q.push(x);

	while(q.size()){
		int fr = q.front();
		q.pop();
		for(int i=0 ; i<adj[fr].size(); i++){
			int child = adj[fr][i];
			if(!mark[child]){
				mark[child] = true;
				h[child] = h[fr] +1;
				q.push(child);
			}
		}
	}
}

int main()
{
	cin >> n >> s >> t;

	for(int i=1 ; i<=n ; i++){
		cin >> ins;
		adj[i].push_back(ins);
	}

	bfs(s);

	if(s!=t && h[t]==0){
		cout << "-1" <<endl;
		return 0;
	}

	cout << h[t] <<endl;

	return 0;
}
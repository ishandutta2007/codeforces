#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int N = (int)2e5 + 9;
int col[N];
int p[N];
vector<int>G[N];
int l = 1;

int main(){
	int n;
	cin >> n;
	int a,b;
	for(int i = 1;i<n;i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	col[1] = 1;
	queue<int>vis;
	vis.push(1);
	int cur;
	int k;
	while(!vis.empty()){
		cur = vis.front();
		vis.pop();
		k = 1;
		for(auto x : G[cur]){
			if(x == p[cur])
				continue;
			while(k == col[cur] or k == col[p[cur]])
				k++;
			col[x] = k;
			p[x] = cur;
			vis.push(x);
			l = max(l,k);
			k++;
		}
	}
	cout << l << "\n";
	for(int i = 1;i<=n;i++)
		cout << col[i] << " ";
	return 0;
}
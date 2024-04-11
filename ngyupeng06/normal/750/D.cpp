#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef long double ld;
typedef pair<ld,li> pdi;
typedef pair<li,li> pll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define inf 2e9

int n, i, j, k, a, b, c, sum, t, cnt, dy[8]={1,1,1,0,-1,-1,-1,0}, dx[8]={-1,0,1,1,1,0,-1,-1};
bool ch, good, vis[2000][2000];
set <pair<int, pair<int, pair<int,int> > > >q;
set <pair<int, pair<int, pair<int,int> > > >::iterator it;

bfs (int x, int y, int di){
	int ct=0;
	while (ct<t){
		ct++;
		x+=dx[di];
		y+=dy[di];
		if (!vis[x][y]) cnt++;
		vis[x][y]=true;
	}
	q.insert(mp(i+1,mp(((di-1)+8)%8,mp(x,y))));
	q.insert(mp(i+1,mp(((di+1)+8)%8,mp(x,y))));
}

int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin >> n;
	q.insert(mp(0,mp(1,mp(1000,1000))));
	for (i=0; i<n; i++){
		cin >> t;
		if (!q.empty()) it = q.begin();
//	cout << "hi\n";
		while (!q.empty()&&(*it).first==i){
			bfs((*it).second.second.first, (*it).second.second.second, (*it).second.first);
	//		cout << "yo\n";
			q.erase(it);
			if (!q.empty()) it = q.begin();
		}
		if (!q.empty()) it = q.begin();
//		cout << "hi\n";
	}
	cout << cnt;
}
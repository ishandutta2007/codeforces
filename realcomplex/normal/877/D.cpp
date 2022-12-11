#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair

const int N = 1005;
int w[N][N];
int s1,s2;
int e1,e2;
int k;
void bfs(){
	queue<pair<int,int>>vis;
	vis.push(mp(s1,s2));
	w[s1][s2]=0;
	int cur1,cur2;
	while(!vis.empty()){
		cur1 = vis.front().fi;cur2 = vis.front().se;
		vis.pop();
		for(int j = cur1+1;j<N&&w[j][cur2]>=w[cur1][cur2]+1&&j<=cur1+k;j++){
			if(w[j][cur2]>w[cur1][cur2]+1){
				w[j][cur2]=w[cur1][cur2]+1;
				vis.push(mp(j,cur2));
			}
		}
		for(int j = cur1-1;j>0&&j>=cur1-k&&w[j][cur2]>=w[cur1][cur2]+1;j--){
			if(w[j][cur2]>w[cur1][cur2]+1){
				w[j][cur2]=w[cur1][cur2]+1;
				vis.push(mp(j,cur2));
			}
		}
		for(int j = cur2+1;j<N&&j<=cur2+k&&w[cur1][j]>=w[cur1][cur2]+1;j++){
			if(w[cur1][j]>w[cur1][cur2]+1){
				w[cur1][j]=w[cur1][cur2]+1;
				vis.push(mp(cur1,j));
			}
		}
		for(int j = cur2-1;j>0&&j>=cur2-k&&w[cur1][j]>=w[cur1][cur2]+1;j--){
			if(w[cur1][j]>w[cur1][cur2]+1){
				w[cur1][j]=w[cur1][cur2]+1;
				vis.push(mp(cur1,j));
			}
		}
	}
}

int main(){
	int n,m;
	cin >> n >> m >> k;
	char s;
	for(int j = 1;j<=n;j++){
		for(int i = 1;i<=m;i++){
			cin >> s;
			if(s=='.')w[j][i] = INT_MAX;
			else w[j][i] = INT_MIN;
		}
	}
	cin >> s1 >> s2 >> e1 >> e2;
	bfs();
	if(w[e1][e2]==INT_MAX){
		cout << -1;
	}
	else{
		cout << w[e1][e2];
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second


int main() {

	int n,x;
	cin >> n >> x;
	vector<int>g[n];
	int a,b;
	for(int i = 0;i<n - 1;i++){
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
	}
	queue<int>walk;
	int distA[n],distB[n];
	distA[0] = 0;
	for(int i = 1;i<n;i++){
        distA[i] = -1;
	}
	for(int i = 0;i<n;i++){
        distB[i] = -1;
	}
	distB[x - 1] = 0;
	walk.push(0);
	while(walk.size() > 0){
        for(int i = 0;i<g[walk.front()].size();i++){
            if(distA[g[walk.front()][i]] == -1){
                distA[g[walk.front()][i]] = distA[walk.front()] + 1;
                walk.push(g[walk.front()][i]);
            }
        }
        walk.pop();
	}
	walk.push(x - 1);
	while(walk.size() > 0){
        for(int i = 0;i<g[walk.front()].size();i++){
            if(distB[g[walk.front()][i]] == -1){
                distB[g[walk.front()][i]] = distB[walk.front()] + 1;
                walk.push(g[walk.front()][i]);
            }
        }
        walk.pop();
	}
	int mx = 0;
	for(int i = 0;i<n;i++){
        if(distA[i] > mx && distB[i] < distA[i]){
            mx = distA[i];
        }
	}
	cout << mx * 2;
	return 0;
}
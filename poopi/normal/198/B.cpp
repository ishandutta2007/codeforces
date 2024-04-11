									/* in the name of Allah */
#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;

#define P pair<int, int>

int n, k;
char ch[2][100010];
int dis[2][100010];
queue <P> q;

bool isposs(int idx, int st, int tm){
	return ch[st][idx] == '-' && tm <= idx && dis[st][idx] == -1;
}

int main(){
	memset(dis, -1, sizeof dis);
	cin >> n >> k;
	scanf("%s", ch[0]);
	scanf("%s", ch[1]);
	q.push(P(0, 0));
	dis[0][0] = 0;
	string res = "NO";
	while(!q.empty()){
		P tmp = q.front();
		q.pop();
		int idx = tmp.first;
		int st = tmp.second;
		int tm = dis[st][idx];
		if(idx + k >= n){
			res = "YES";
			break;
		}
		if(isposs(idx - 1, st, tm + 1)){
			dis[st][idx - 1] = tm + 1;
			q.push(P(idx - 1, st));
		}
		if(isposs(idx + 1, st, tm + 1)){
			dis[st][idx + 1] = tm + 1;
			q.push(P(idx + 1, st));
		}
		if(isposs(idx + k, 1 - st, tm + 1)){
			dis[1 - st][idx + k] = tm + 1;
			q.push(P(idx + k, 1 - st));
		}
	}
	cout << res << endl;
	return 0;
}
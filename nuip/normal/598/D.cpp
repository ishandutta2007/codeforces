#include<bits/stdc++.h>
using namespace std;

#define rep(i,j) for(int i=0;i<(j);i++)
#define eb emplace_back
#define all(X) (X).begin(),(X).end()
#define Re real()
#define Im imag()
#define X first
#define Y second

typedef pair<int,int> pii;
typedef long long ll;
#define N 1000
int n,table[N][N],m,k,cnt;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int main(){
	map<int,int> mp;
	cin >> n >> m >> k;
	vector<string> str(n);
	rep(i,n) cin >> str[i];
	rep(i,k){
		int s,t,ans=0;
		cin >> s >> t;
		if(table[--s][--t]!=0){
			cout << mp[table[s][t]] << endl;
			continue;
		}
		table[s][t] = ++cnt;
		queue<pii> q;
		q.push(pii(s,t));
		while(!q.empty()){
			int x,y;
			x = q.front().X; y = q.front().Y; q.pop();
			rep(j,4){
				int cx = x + dx[j], cy = y + dy[j];
				if(0<=cx && cx<n && 0<=cy && cy<m){
					if(str[cx][cy] == '*') ans++;
					else if(table[cx][cy]==0){
						table[cx][cy]=cnt;
						q.push(pii(cx,cy));
					}
				}
			}
		}
		cout << (mp[cnt] = ans) << endl;
	}
	return 0;
}
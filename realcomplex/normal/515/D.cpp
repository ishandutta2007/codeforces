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

const int N = 2002;
const int L = (int)2e9 + 9;
int conf[N][N];
char ans[N][N];

int count(int i,int j){
	int a = 0;
	if(conf[i+1][j] == L)
		a++;
	if(conf[i-1][j] == L)
		a++;
	if(conf[i][j+1] == L)
		a++;
	if(conf[i][j-1] == L)
		a++;
	return a;
}

int main(){
	fastIO;
	int n,m;
	cin >> n >> m;
	for(int i = 0;i<N;i++)for(int j = 0;j<N;j++)conf[i][j] = -1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin >> ans[i][j];
			if(ans[i][j]=='.')
				conf[i][j] = L;
		}
	}
	queue<pii>vis;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(conf[i][j] == L)
			if(count(i,j) == 1){
				vis.push(mp(i,j));
			}
		}
	}
	int cx,cy;
	int li,ri;
	while(!vis.empty()){
		cx = vis.front().fi;
		cy = vis.front().se;
		vis.pop();
		li = cx;
		ri = cy;
		if(conf[li][ri] != L)
			continue;
		if(count(li,ri) != 1)
			continue;
		if(conf[li][ri] == -1)
			continue;
		conf[li][ri] = 0;
		if(conf[cx-1][cy] == L){
			ans[cx-1][cy] = '^';
			ans[cx][cy] = 'v';
			li--;
		}
		else if(conf[cx+1][cy] == L){
			ans[cx+1][cy] = 'v';
			ans[cx][cy] = '^';
			li++;
		}
		else if(conf[cx][cy+1] == L){
			ans[cx][cy+1] = '>';
			ans[cx][cy] = '<';
			ri++;
		}
		else{
			ans[cx][cy-1] = '<';
			ans[cx][cy] = '>';
			ri--;
		}
		conf[li][ri] = 0; // visited state
		if(conf[li][ri+1]== L and count(li,ri+1) == 1){
			vis.push(mp(li,ri+1));
		}
		if(conf[li][ri-1] == L and count(li,ri-1) == 1){
			vis.push(mp(li,ri-1));
		}
		if(conf[li+1][ri] == L and count(li+1,ri) == 1){
			vis.push(mp(li+1,ri));
		}
		if(conf[li-1][ri] == L and count(li-1,ri) == 1){
			vis.push(mp(li-1,ri));
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(ans[i][j] == '.'){
				cout << "Not unique\n";
				return 0;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j <= m;j++){
			cout << ans[i][j];
		}
		cout << "\n";
	}
	return 0;
}
/**
*    author:  t0urist
*    created: 10.08.1919 11:45:14
**/

#include<bits/stdc++.h>
using namespace std;

int n;

#define MAX 1000005

char buf[5];
struct st{
	string ope;
	int a;
	int b;
	int x;
	void read(){
		scanf("%s", buf);
		ope = buf;
		if (ope == "IN"){
			scanf("%d", &x);
			return;
		}
		scanf("%d", &a);
		a--;
		if (ope == "NOT"){
			return;
		}
		scanf("%d", &b);
		b--;
	}
};

vector<st> v;

int dp[MAX][2];
int val[MAX];

int par[MAX];

void dfs(int b,int pr=-1){
	par[b] = pr;
	if (v[b].ope[0] == 'A' || v[b].ope[0] == 'X' || v[b].ope[0] == 'O'){
		dfs(v[b].a,b);
		dfs(v[b].b,b);
		if (v[b].ope[0] == 'A'){
			val[b] = (val[v[b].a]&val[v[b].b]);
		}
		if (v[b].ope[0] == 'X'){
			val[b] = (val[v[b].a]^val[v[b].b]);
		}
		if (v[b].ope[0] == 'O'){
			val[b] = (val[v[b].a]|val[v[b].b]);
		}
		return;
	}
	if (v[b].ope[0] == 'I'){
		val[b] = v[b].x;
		return;
	}
	if (v[b].ope[0] == 'N'){
		dfs(v[b].a,b);
		val[b] = val[v[b].a] ^ 1;
	}
	return;
}
bool us[MAX][2];
int calc(int b, int chang){
	int mode = 0;
	if (v[b].a == chang){
		mode = 0;
	}
	else{
		mode = 1;
	}
	chang = mode;
	if (us[b][mode])return dp[b][mode];
	us[b][mode] = true;
	int val2;
	if (v[b].ope[0] == 'A' || v[b].ope[0] == 'X' || v[b].ope[0] == 'O'){
		int A = val[v[b].a] ^ (mode ^ 1);
		int B = val[v[b].b]^mode;
		if (v[b].ope[0] == 'A'){
			val2 = (A&B);
		}
		if (v[b].ope[0] == 'X'){
			val2 = (A^B);
		}
		if (v[b].ope[0] == 'O'){
			val2 = (A|B);
		}
	}
	if (v[b].ope[0] == 'N'){
		val2 = val[b] ^ 1;
	}
	if (val2 == val[b]){
		dp[b][chang] = val[0];
		return val[0];
	}
	if (b == 0){
		dp[b][chang] = val2;
		return val2;
	}
	dp[b][chang] = calc(par[b], b);
	return dp[b][chang];
}
string ans;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		v.push_back(st());
		v.back().read();
	}
	dfs(0);
	for (int i = 0; i < v.size(); i++){
		if (v[i].ope[0] == 'I'){
			int th=calc(par[i], i);
			ans.push_back(th + '0');
		}
	}
	printf("%s\n", ans.c_str());
	return 0;
}
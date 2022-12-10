#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 5e3 + 85 - 69;
char v[maxn][maxn];
vector<int> vec;
int mark[maxn];
int n;
char c;

void dfs(int x){
	mark[x] = 1;
	vec.PB(x);
	for(int y = 1; y <= n; y++) if(v[x][y - 1] == '1'){
		if(!mark[y])
			dfs(y);
		else if(mark[y] == 1){
			while(1){
				int xx = vec.back();
				vec.pop_back();
				int yy = vec.back();
				vec.pop_back();
				int zz = vec.back();
				vec.pop_back();
				if(v[xx][zz - 1] == '1'){
					cout << zz << ' ' << yy << ' ' << xx << endl;
					exit(0);
				}
				else
					vec.PB(zz), vec.PB(xx);
			}
		}
	}
	vec.pop_back();
	mark[x] = 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	vec.reserve(n + 10);
	for(int i = 1; i <= n; i++)
		scanf("%s", v[i]);
	for(int i = 1; i <= n; i++)
		if(!mark[i])
			dfs(i);
	cout << -1 << endl;
	return 0;
}
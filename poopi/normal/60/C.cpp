							/* in the name of Allah */
#include <iostream>
#include <vector>
#include <memory.h>
#include <cstdlib>
using namespace std;

#define Max 1000001
#define int64 long long

int n, m;
int64 p;
bool npr[Max];
bool mark[Max];
vector <int> pr;
int num[110];
bool mar[110], vis[110];
int poss[10000], dv[Max];
int g[110][110], l[110][110];
int ini[110][2];
int hav[110];

int gcd(int a, int b){
	return (b == 0 ? a : gcd(b, a % b));
}

void find_prime(){
	for(int i = 2; i < Max; i++){
		if(!npr[i]){
			pr.push_back(i);
			dv[i] = i;
			for(int j = 2*i; j < Max; j += i)
				npr[j] = true, dv[j] = i;
		}
	}
}

bool dfs(int idx){
	bool ret = true;
	vis[idx] = true;
	for(int i = 0; i < n; i++){
		if(g[idx][i] == -1) continue;
		//cout << "DF " << idx << ' ' << i << endl;
		int tmp, t1 = gcd(p, g[idx][i]), t2 = gcd(p, l[idx][i]);
		if(t1 == hav[idx])
			tmp = t2;
		else if(t2 == hav[idx])
			tmp = t1;
		else return false;
		if(vis[i]){
			if(hav[i] != tmp)
				return false;
		}
		else{
			hav[i] = tmp;
			if(!dfs(i))
				return false;
		}
	}
	return ret;
}

int main(){
	int cnt = 0;
	find_prime();
	cin >> n >> m;
	int a, b;
	memset(g, -1, sizeof g);
	memset(l, -1, sizeof l);
	memset(ini, -1, sizeof ini);
	bool can = true;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--, b--;
		cin >> g[a][b] >> l[a][b];
		g[b][a] = g[a][b];
		l[b][a] = l[a][b];
		if(l[a][b] % g[a][b] != 0)
			can = false;
		ini[a][0] = g[a][b], ini[a][1] = l[a][b];
		ini[b][0] = g[a][b], ini[b][1] = l[a][b];
		int t = l[a][b];
		while(t > 1){
			if(!mark[dv[t]]){
				mark[dv[t]] = true;
				poss[cnt++] = dv[t];
			}
			t /= dv[t];
		}
	}
	for(int i = 0; i < n; i++)
		num[i] = 1;
	for(int ii = 0; ii < cnt && can; ii++){
		int x = poss[ii];
		p = x;
		while(p * x < Max) p *= x;
		memset(vis, false, sizeof vis);
		//cout << x << ' ' << p << endl;
		for(int i = 0; i < n; i++){
			if(vis[i] || ini[i][1] == -1) continue;
			hav[i] = gcd(p, ini[i][0]);
			memcpy(mar, vis, sizeof mar);
			//cout << i << ' ' << hav[i] << ' ' << ini[i][0] << " S "<< endl;
			if(!dfs(i)){
				hav[i] = gcd(p, ini[i][1]);
				memcpy(vis, mar, sizeof mar);
				//for(int i = 0; i < n; i++)
				//	cout << vis[i] << ' ';
				//cout << endl;
				if(!dfs(i))
					can = false;
			}
		}
		//cout << can << endl;
		for(int i = 0; i < n; i++){
			if(vis[i])
				num[i] *= hav[i];
		}
	}
	if(can){
		cout <<	"YES" << endl;
		for(int i = 0; i < n; i++){
			if(i > 0) cout << ' ';
			cout << num[i];
		}
		cout << endl;
	}
	else cout << "NO" << endl;
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

bool mark[510];
int x[510], y[510], sz[510];
int d[510], as[510];

int main(){
	int n, m;
	while(cin >> n >> m){
		for(int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		for(int i = 0; i < m; i++)
			cin >> sz[i];
		for(int i = 0; i < n; i++){
			int bef = (i + n - 1) % n;
			int nex = (i + 1) % n;
			d[i] = abs(x[i] - x[bef]) + abs(x[i] - x[nex]) + abs(y[i] - y[bef]) + abs(y[i] - y[nex]);
		}
		bool fl = true;
		for(int i = 0; i < 2; i++){
			memset(mark, false, sizeof mark);
			memset(as, -1, sizeof as);
			fl = true;
			for(int j = i; j < n; j += 2){
				for(int k = 0; k < m; k++){
					if(sz[k] == d[j] && !mark[k]){
						mark[k] = true;
						as[j] = k + 1;
						break;
					}
				}
				if(as[j] == -1)
					fl = false;
			}
			if(fl == true)
				break;
		}
		if(fl){
			cout << "YES" << endl;
			for(int i = 0; i < n; i++){
				if(i > 0) cout << ' ';
				cout << as[i];
			}
			cout << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

#define MAX 45

int n;
int m;
int q;


int im[MAX][MAX];

char buf[MAX];

int rec(int x, int y, int xx, int yy){
	return im[xx][yy] + im[x - 1][y - 1] - im[xx][y - 1] - im[x - 1][yy];
}





vector<pair<int,int> > push[MAX][MAX];

struct st{
	int y;
	int id;
	int mul;
	int a;
	int b;
	int c;
	int d;
};

vector<st> ev[MAX][MAX];

int ans[300002];

struct BIT{
	int B[MAX][MAX];
	BIT(){
		memset(B, 0, sizeof(B));
	}
	void add(int x, int y, int d){
		x++;
		y++;
		while (x < MAX){
			int Y = y;
			while (Y < MAX){
				B[x][Y] += d;
				Y += Y&-Y;
			}
			x += x&-x;
		}
	}

	int sum(int x, int y){
		x++;
		y++;
		int r = 0;
		while (x){
			int Y = y;
			while (Y){
				r += B[x][Y];
				Y -= Y&-Y;
			}
			x -= x&-x;
		}
		return r;
	}

	int rec2(int x, int y, int xx, int yy){
		return sum(xx, yy) + sum(x - 1, y - 1) - sum(xx, y - 1) - sum(x - 1, yy);
	}
};

BIT b[MAX];

int main(){
	cin >> n >> m >> q;
	int Q = q;
	for (int i = 1; i <= n; i++){
		scanf("%s", buf);
		for (int j = 1; j <= m; j++){
			im[i][j] = buf[j - 1] - '0';
		}
	}
	int I = 0;
	while (q--){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		ev[a][b].push_back({d,I,1,a,b,c,d});
		ev[c + 1][b].push_back({ d, I, -1,a,b,c,d });
		I++;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			im[i][j] += im[i][j - 1];
		}
	}
	for (int j = 1; j <= m; j++){
		for (int i = 1; i <= n; i++){
			im[i][j] += im[i - 1][j];
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			for (int k = i; k <= n; k++){
				for (int kk = j; kk <= m; kk++){
					int r = rec(i, j, k, kk);
					if (r == 0){
						b[j].add(k, kk, 1);
						push[i][j].push_back(make_pair(k,kk) );
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			vector<st> &v = ev[i][j];
			for (int k = 0; k < v.size(); k++){
				for (int kk = v[k].b; kk <= v[k].d; kk++){
					ans[v[k].id] += v[k].mul*b[kk].rec2(v[k].a, j, v[k].c, v[k].y);
				}
			}
		}
		//end
		for (int j = 1; j <= m; j++){
			vector<pair<int,int> > &v = push[i][j];
			for (int k = 0; k < v.size(); k++){
				b[j].add(v[k].first, v[k].second, -1);
			}
		}
	}
	for (int i = 0; i < Q; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}
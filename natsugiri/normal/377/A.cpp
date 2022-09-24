#include<queue>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const int dy[] = {0, 1, 0, -1}, dx[] = {1, 0, -1, 0};

struct Data {
    int y, x, l;
    Data(){}
    Data(int y, int x, int l) :y(y),x(x),l(l){}
};
bool operator<(const Data&a, const Data&b) {
    return a.l > b.l;
}

int N, M, K;
char F[512][512];
int len[512][512];

bool in(int y, int x) {
    return 0<=y && y<N && 0<=x && x<M;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i=0; i<N; i++) scanf("%s", F[i]);

    int sy=0, sx=0;
    for (int i=0; i<N; i++) {
	for (int j=0; j<M; j++) {
	    if (F[i][j] == '.') {
		sy = i;
		sx = j;
	    }
	}
    }

    queue<pair<int,int> > qu;
    qu.push(make_pair(sy, sx));

    memset(len, 0x3f, sizeof len);
    len[sy][sx] = 0;

    for (; !qu.empty();) {
	int y = qu.front().first;
	int x = qu.front().second;
	qu.pop();
	
	for (int d=0; d<4; d++) {
	    int yy = y+dy[d], xx = x+dx[d];
	    if (in(yy, xx) && F[yy][xx] == '.' && len[yy][xx] > len[y][x] + 1) {
		len[yy][xx] = len[y][x] + 1;
		qu.push(make_pair(yy, xx));
	    }
	}
    }

    vector<Data>v;
    for (int i=0; i<N; i++) {
	for (int j=0; j<M; j++) {
	    if (F[i][j] == '.') v.push_back(Data(i, j, len[i][j]));
	}
    }

    sort(v.begin(), v.end());

    for (int i=0; i<K; i++) {
	int y = v[i].y;
	int x = v[i].x;

	F[y][x] = 'X';
    }

    for (int i=0; i<N; i++) printf("%s\n", F[i]);


    return 0;
}
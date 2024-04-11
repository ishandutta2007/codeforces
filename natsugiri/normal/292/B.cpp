#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<vector<int> > Mat;

int N, M;
Mat G;

bool bus() {
    int one=0, two=0;
    for (int i=0; i<N; i++) {
	if (int(G[i].size())==1) one++;
	if (int(G[i].size())==2) two++;
    }
    return one==2 && two==N-2;
}
bool ring() {
    for (int i=0; i<N; i++) if (int(G[i].size())!=2) return false;
    return true;
}
bool star() {
    int one=0, many=0;
    for (int i=0; i<N; i++) {
	if (int(G[i].size())==1) one++;
	if (int(G[i].size())==N-1) many++;
    }
    return one==N-1 && many==1;
}
int main() {
    scanf("%d%d", &N, &M);
    G=Mat(N);
    for (int i=0; i<M; i++) {
	int x, y;
	scanf("%d%d", &x, &y); x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
    if (bus()) puts("bus topology");
    else if (ring()) puts("ring topology");
    else if (star()) puts("star topology");
    else puts("unknown topology");
    return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef pair < int, int > pii;

const int N = 2e5 + 500;

int n, a[N], b[N], deg[N], bio[N], poc[N];
vector < int > saz;
vector < pii > v[N];

void euler(int x){
	for(;(int)v[x].size() > 0;){
		int nw = v[x].back().Y;
		int gd = v[x].back().X;
		v[x].pop_back();
		if(bio[nw]) continue;
		poc[nw] = x; 
		bio[nw] = 1;
		euler(gd);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d%d", a + i, b + i);
		b[i]++;
		saz.PB(a[i]), saz.PB(b[i]);
	}
	sort(saz.begin(), saz.end());
	saz.erase(unique(saz.begin(), saz.end()), saz.end());
	for(int i = 0;i < n;i++){
		a[i] = lower_bound(saz.begin(), saz.end(), a[i]) - saz.begin();
		b[i] = lower_bound(saz.begin(), saz.end(), b[i]) - saz.begin();
		v[a[i]].PB({b[i], i}), v[b[i]].PB({a[i], i});
		deg[a[i]]++, deg[b[i]]++;
	}
	vector < int > nep;
	for(int i = 0;i < N;i++)
		if(deg[i] & 1) nep.PB(i);
	for(int i = 0;i < (int)nep.size();i += 2){
		v[nep[i]].PB({nep[i + 1], i / 2 + n});
		v[nep[i + 1]].PB({nep[i], i / 2 + n});
		deg[nep[i]]++, deg[nep[i + 1]]++;
	}
	for(int i = 0;i < N;i++) euler(i);
	for(int i = 0;i < n;i++)
		printf("%d ", poc[i] == a[i]);
	printf("\n");
	return 0;
}
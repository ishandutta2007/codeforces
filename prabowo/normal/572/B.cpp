#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,m,p,q,maps[1000],cnt[2][100005],cnta;
vector<pair<int,int> > vec;
#define pb push_back
char mode;
#define mp make_pair
char apalah[100];
int main() {
	scanf("%d %d",&n,&m);
	gets(apalah);
	maps[(int)'B'] = 1;
	for (int i=0;i<n;i++) {
		scanf("%c %d %d",&mode,&p,&q);
//		cout << mode << endl;
		gets(apalah);
		cnt[maps[mode]][p] += q;
	}
	for (int i=0;i<=100000;i++) {
		if (cnt[0][i] > 0) {
			vec.pb(mp(i,cnt[0][i]));
			cnta++;
		}
		if (cnta == m) break;
	}
	while (!vec.empty()) {
		printf("S %d %d\n",vec.back().first,vec.back().second);
		vec.pop_back();
	}
	cnta = 0;
	for (int i=100000;i>=0;i--) {
		if (cnt[1][i] > 0) {
			printf("B %d %d\n",i,cnt[1][i]);
			cnta++;
		}
		if (cnta == m) break;
	}

}
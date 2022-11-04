#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 505;
int n, k, cnt, ans[2], b[N], c[N];
vector<int> a;
pair<int,int> query(const vector<int> &a){
	printf("?");
	for(int i:a) printf(" %d", i);
	puts("");
	fflush(stdout);
	int x, y;
	scanf("%d%d", &x, &y);
	return make_pair(x, y);
}
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1; i<k; ++i) a.push_back(i);
	for(int i=k; i<=n; ++i){
		a.push_back(i);
		auto x=query(a);
		for(int i=0; i<k; ++i) if(a[i]==x.first){
			a.erase(a.begin()+i);
			b[++cnt]=x.first, c[cnt]=x.second;
			break;
		}
	}
	for(int i=0; i<k-1; ++i){
		vector<int> aa=a;
		aa.erase(aa.begin()+i);
		aa.push_back(b[1]), aa.push_back(b[2]);
		auto x=query(aa);
		++ans[x.first==b[1]];
	}
	printf("! %d\n", 1+ans[c[1]>c[2]]);
	fflush(stdout);
	return 0;
}
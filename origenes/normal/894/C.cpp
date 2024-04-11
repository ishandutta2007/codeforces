#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define llrd(a) scanf("%I64d", &a)
#define rd(a) scanf("%d", &a)
#define llpt(a) printf("%I64d", a)
#define pt(a) printf("%d ", a)
#define M3 1123
#define M4 11234
#define M5 112345
#define M6 1123456
#define M7 11234567
#define MOD 1000000007LL
set<int> tmp;
int m, s[M3], cur;
int main(){
	rd(m);
	for(int i=0; i<m; i++){
		rd(s[i]);
		tmp.insert(s[i]);
	}
	int cur=*tmp.begin();
	for(auto it:tmp)
		if(it%cur) return puts("-1")<0;
	pt(2*m);
	puts("");
	for(auto it:tmp)
		pt(it), pt(cur);
	puts("");
	return 0;
}
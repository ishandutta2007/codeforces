#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;


map<int,int>mp;
int n, ans, bad;
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
	int id; scanf("%d", &id);
	if (id) {
	    mp[id]++;
	    if (mp[id]==2) ans++;
	    if (mp[id]>2) bad=1;
	}
    }
    if (bad) puts("-1");
    else printf("%d\n", ans);
    return 0;
}
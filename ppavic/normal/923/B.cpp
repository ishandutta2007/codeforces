#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

typedef long long llint;

const int MAXN = 100005;

llint n, ofs;
llint v[MAXN], t[MAXN];
multiset <llint> s;
multiset <llint> :: iterator it;

int main () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		scanf("%I64d", &v[i]);
	}
	for (int i=1; i<=n; i++) {
        scanf("%I64d", &t[i]);
        s.insert(v[i]+ofs);
        llint sol=0, cnt=0, siz=s.size();
        while (!s.empty()) {
            it=s.begin();
            llint val=*it-ofs;
            if (val<=t[i]) {
                sol+=val;
                cnt++;
                s.erase(it);
            } else break;
        }
        sol+=(siz-cnt)*t[i];
        ofs+=t[i];
        printf("%I64d ", sol);
	}
	return 0;
}
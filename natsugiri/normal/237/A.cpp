#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
    int n, h, m;
    vector<pair<int, int> >v;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
	scanf("%d%d", &h, &m);
	v.push_back(make_pair(h, m));
    }
    sort(v.begin(), v.end());
    h=m=0;
    int ma=0;
    for (int i=0; i<n; i++) {
	if (v[i]==v[h]) m++;
	else {
	    m=1;
	    h=i;
	}
	ma=max(ma, m);
    }
    printf("%d\n", ma);

    return 0;
}
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


int main() {
    int X, K;
    scanf("%d%d", &X, &K);
    
    vector<pair<int,int> > v;
    
    v.push_back(make_pair(0, 0));
    v.push_back(make_pair(X, X));
    
    for (int i=0; i<K; i++) {
	int t, a, b;
	scanf("%d%d", &t, &a);
	if (t==1) {
	    scanf("%d", &b);
	} else {
	    b = a;
	}
	v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());
	    
    int ma = 0, mi = 0;
    for (int i=0; i<(int)v.size()-1; i++) {
	int d = v[i+1].first - v[i].second - 1;
	ma += d;
	mi += (d+1)/2;
    }
    printf("%d %d\n", mi, ma);
    
    return 0;
}
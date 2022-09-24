#include<map>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const int MAX = 100010;


int main() {

    int M;
    scanf("%d", &M);
    vector<int>num;
    vector<pair<LL, int> > start;
    map<LL, int> single;
    LL len = 0;

    for (int i=0; i<M; i++) {
	int t;
	scanf("%d", &t);
	if (t==1) {
	    int x;
	    scanf("%d", &x);
	    single[len] = x;
	    if ((int)num.size() < MAX) num.push_back(x);
	    len++;
	} else {
	    int l, c;
	    scanf("%d%d", &l, &c);
	    start.push_back(make_pair(len, l));

	    for (int i=0; i<(LL)l*c && (int)num.size() < MAX; i++) {
		num.push_back(num[i % l]);
	    }
	    len += (LL)l*c;
	}
    }
    start.push_back(make_pair(len, 1));
    sort(start.begin(), start.end());


    
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	if (i) putchar(' ');

	LL x;
	cin >> x;
	x--;
	if (single.count(x)) printf("%d", single[x]);
	else {
	    while (x >= (int)num.size()) {
		int p = lower_bound(start.begin(), start.end(), make_pair(x, 1<<29)) - start.begin();
		p--;

		x = (x - start[p].first) % start[p].second;
	    }
	    printf("%d", num[x]);
	}
    }	    
    puts("");

    return 0;
}
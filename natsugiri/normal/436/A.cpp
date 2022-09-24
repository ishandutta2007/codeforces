#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

typedef long long LL;

int solve(vector<pair<int,int> > A, vector<pair<int, int> > B, int H) {
    priority_queue<int> QA, QB;
    int ans = 0;
    while (true) {
	while (A.size() && A.back().first <= H) {
	    QA.push(A.back().second);
	    A.pop_back();
	}
	if (QA.empty()) return ans;
	H += QA.top(); QA.pop();
	ans++;
	
	while (B.size() && B.back().first <= H) {
	    QB.push(B.back().second);
	    B.pop_back();
	}
	if (QB.empty()) return ans;
	H += QB.top(); QB.pop();
	ans++;
    }
}

int N, X;
vector<pair<int,int> > A, B;
int main() {
    scanf("%d%d", &N, &X);
    for (int i=0; i<N; i++) {
	int t, h, m;
	scanf("%d%d%d", &t, &h, &m);
	if (t == 0) A.push_back(make_pair(h, m));
	else B.push_back(make_pair(h, m));
    }

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    printf("%d\n", max(solve(A, B, X), solve(B, A, X)));

    return 0;
}
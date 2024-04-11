#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const int S =  1000000;

int N, X[500010];
bool B[1000010];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	scanf("%d", X+i);
	B[X[i]] = true;
    }

    vector<int>ans;
    int cnt = 0;
    for (int i=1; i<=S; i++) {
	if (B[i]) {
	    if (B[S+1-i]) cnt++;
	    else ans.push_back(S+1-i);
	}
    }
    for (int i=1; cnt; i++) {
	if (!B[i] && !B[S+1-i]) {
	    ans.push_back(i);
	    ans.push_back(S+1-i);
	    cnt -= 2;
	}
    }

    printf("%d\n", ans.size());
    for (int i=0; i<(int)ans.size(); i++) {
	printf("%d%c", ans[i], i+1 == (int)ans.size() ? '\n' : ' ' );
    }
    return 0;
}
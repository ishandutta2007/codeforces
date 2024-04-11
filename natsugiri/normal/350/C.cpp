#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const char dir[] = "RULD";

int N;
pair<int,int>Z[100010];
bool cmp(const pair<int,int>&a, const pair<int,int>&b) {
    return abs((LL)a.first)+abs((LL)a.second) < abs((LL)b.first)+abs((LL)b.second);
}


int calc(bool out) {
    int cnt=0;
    for (int i=0; i<N; i++) {
	if (Z[i].first == 0) {
	    if (out) {
		int d = (Z[i].second > 0 ? 1 : 3);
		printf("1 %d %c\n", abs(Z[i].second), dir[d]);
		puts("2");
		printf("1 %d %c\n", abs(Z[i].second), dir[(d+2)%4]);
		puts("3");
	    }
	    cnt+=4;
	} else if (Z[i].second == 0) {
	    if (out) {
		int d = (Z[i].first > 0 ? 0 : 2);
		printf("1 %d %c\n", abs(Z[i].first), dir[d]);
		puts("2");
		printf("1 %d %c\n", abs(Z[i].first), dir[(d+2)%4]);
		puts("3");
	    }
	    cnt+=4;
	} else {
	    if (out) {
		int d0 = (Z[i].first > 0 ? 0 : 2);
		int d1 = (Z[i].second > 0 ? 1 : 3);
		printf("1 %d %c\n", abs(Z[i].first), dir[d0]);
		printf("1 %d %c\n", abs(Z[i].second), dir[d1]);
		puts("2");
		printf("1 %d %c\n", abs(Z[i].first), dir[(d0+2)%4]);
		printf("1 %d %c\n", abs(Z[i].second), dir[(d1+2)%4]);
		puts("3");
	    }
	    cnt+=6;
	}
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d%d", &Z[i].first, &Z[i].second);
    sort(Z, Z+N, cmp);

    printf("%d\n", calc(false));
    calc(true);

    return 0;
}
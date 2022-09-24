#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

struct Data {
    int a, b, id;
};
bool cmp1(const Data&x, const Data&y) {
    return x.b!=y.b ? x.b > y.b :
	x.a != y.a ? x.a < y.a :
	x.id < y.id;
}
bool cmp2(const Data&x, const Data&y) {
    return x.a > y.a;
}

int N, P, K;
Data data[100010];
bool use[100010];

int main() {
    scanf("%d%d%d", &N, &P, &K);
    for (int i=0; i<N; i++) {
	int a, b; scanf("%d%d", &a, &b);
	data[i].a = a;
	data[i].b = b;
	data[i].id = i;
    }
    sort(data, data+N, cmp1);
    //for (int i=0; i<N; i++) { printf("(%d %d)%d, ", data[i].a, data[i].b, data[i].id+1); } puts("");    
    stable_sort(data, data+N-P+K, cmp2);
    //for (int i=0; i<N; i++) { printf("%d ", data[i].id+1); } puts("");
	
    for (int i=0; i<K; i++) {
	printf("%d ", data[i].id + 1);
	use[data[i].id] = true;
    }

    sort(data, data+N, cmp1);
    //puts("");
    //for (int i=0; i<N; i++) { printf("%d ", data[i].id+1); } puts("");
    int cnt=0, t;
    for (t=0; t<N; t++) {
	if (use[data[t].id]) cnt++;
	if (cnt==K) break;
    }
    t++;

    for (int i=0; i<P-K; i++) printf("%d ", data[t+i].id + 1); 
    
    return 0;
}
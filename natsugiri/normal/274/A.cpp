#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
using namespace std;


typedef long long LL;


int N, K, a[100010];
set<int>se;
int main() {
    cin>>N>>K;
    for (int i=0; i<N; i++) scanf("%d", a+i);
    sort(a, a+N);
    
    for (int i=0; i<N; ++i) {
	if (a[i]%K==0 && se.count(a[i]/K)) continue;
	else se.insert(a[i]);
    }
    printf("%d\n", se.size());
    return 0;
}
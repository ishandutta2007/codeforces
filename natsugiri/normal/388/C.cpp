#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

int N, S[128];
vector<int>v;

int ciel, jiro;

int main() {
    
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	scanf("%d", S+i);
	for (int j=0; j<S[i]; j++) {
	    int a;
	    scanf("%d", &a);

	    if (j<S[i]/2) ciel += a;
	    else if (S[i]%2 == 1 && j == S[i]/2) v.push_back(a);
	    else jiro += a;
	}
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i=0; i<(int)v.size(); i++) {
	if (i % 2 == 0) ciel += v[i];
	else jiro += v[i];
    }

    printf("%d %d\n", ciel, jiro);

    return 0;
}
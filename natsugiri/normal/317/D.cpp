#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<map>
using namespace std;

typedef long long LL;

const int X[]={0,1,2,1,4,3,2,1,5,6, 2,1,8,7,5,9,8,7,3,4, 7,4,2,1,10,9,3,6,11,12, 14,1};
bool use[100000];

int main() {
    int N, M;
    scanf("%d", &N);
    int nim=0;
    LL i;
    M=N;
    for (i=2; i*i<=N; i++) {
	if (!use[i]) {
	    int cnt=0;
	    for (LL j=i; j<=N; j*=i) {
		cnt++;
		if (j<100000) use[j]=true;
		M--;
	    }
	    nim ^= X[cnt];
	}
    }
    if (M%2) nim ^= 1;
    puts(nim?"Vasya":"Petya");
    return 0;
}
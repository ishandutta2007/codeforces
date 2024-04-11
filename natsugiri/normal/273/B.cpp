#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;


typedef long long LL;

int N, M, a[100010], b[100010];

map<int,int>mp, cnt;

LL calc(int x, int y, LL mod) {
    LL r=1;
    for (int i=1; i<=x; i++) {
	LL t=i;
	for (;y>0 && ~t&1;) { t>>=1; y--; }
	r=r*t%mod;
    }
    return r;
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", a+i);
    for (int i=0; i<N; i++) scanf("%d", b+i);
    scanf("%d", &M);

    for (int i=0; i<N; i++) {
	if (a[i]==b[i]) mp[a[i]]++;
	cnt[a[i]]++; cnt[b[i]]++;
    }

    LL ans=1;
    for (map<int,int>::iterator it=cnt.begin(); it!=cnt.end(); it++) {
	ans=ans*calc(it->second, mp[it->first], M)%M;
    }

    printf("%d\n", int(ans));    
    return 0;
}
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
using namespace std;

typedef long long LL;

void get(int N, int*A) {
    for (int i=0; i<N; i++) scanf("%d", A+i);
}

void update(map<int,int>&nums, map<int,int>&mp, int &cnt, int v, int i) {
    if (nums[v] == mp[v]) cnt--;
    nums[v] += i;
    if (nums[v] == mp[v]) cnt++;
}

int N, M, A[200010], B[200010], P;



int main() {
    scanf("%d%d%d", &N, &M, &P);
    get(N, A);
    get(M, B);

    vector<int>ans;
    map<int,int> mp;
    for (int i=0; i<M; i++) mp[B[i]]++;

    const int COUNT = mp.size();

    for (LL i=0; i<P && i<N; i++) {

	map<int,int> nums;
	int cnt = 0;
	
	for (LL j=0; j<M; j++) {
	    LL x=i+j*P;
	    if (x>=N) break;
	    update(nums, mp, cnt, A[x], 1);
	}

	for (LL q=i, t=q+(M-1LL)*(LL)P; t<N; q+=P, t+=P) {

	    if (cnt==COUNT) ans.push_back((int)q);

	    if (t+P >= N) break;
	    update(nums, mp, cnt, A[q], -1);
	    update(nums, mp, cnt, A[t+P], 1);
	}
    }

    sort(ans.begin(), ans.end());

    printf("%d\n", ans.size());
    for (int i=0; i<(int)ans.size(); i++) {
	printf("%d%c", ans[i]+1, i==(int)ans.size()-1 ? '\n' : ' ');
    }
	    
    

    return 0;
}
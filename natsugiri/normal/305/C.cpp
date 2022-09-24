#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

typedef long long LL;

int N;
map<LL,int>mp;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
	LL x;
	cin>>x;
	mp[x]++;
    }
    vector<LL>v;
    for (__typeof(mp.end()) it=mp.begin(); it!=mp.end(); it++) {
	LL x=it->first;
	while (mp[x]>1) {
	    mp[x+1] += mp[x]/2;
	    mp[x] = mp[x]%2;
	    x++;
	}
	if (it->second==1) v.push_back(it->first);
    }
    LL p=0, ans=0;
    for (int i=0; i<int(v.size()); i++) {
	ans += v[i]-p;
	p=v[i]+1;
    }
    cout<<ans<<endl;
	

    return 0;
}
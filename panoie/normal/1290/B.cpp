#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, q;
char s[N];
vector<int> a[26];
int main() {
	scanf("%s%d", s+1, &q), n=strlen(s+1);
	for(int i=1; i<=n; ++i) a[s[i]-'a'].push_back(i);
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		if(s[l]!=s[r] || l==r) puts("Yes");
		else{
			int cnt=0;
			for(int i=0; i<26; ++i){
				int x=lower_bound(a[i].begin(), a[i].end(), l)-a[i].begin();
				if(x<(int)a[i].size() && a[i][x]<=r) ++cnt;
			}
			if(cnt>=3) puts("Yes"); else puts("No");
		}
	}
	return 0;
}
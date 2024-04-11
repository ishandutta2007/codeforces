#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void work() {
	string s;
	cin>>n>>s;
	int to[26],from[26];
	memset(to,-1,sizeof(to));
	memset(from,-1,sizeof(from));
	string t(n,' ');
	for (int i=0;i<n;i++) {
		if (to[s[i]-'a']<0) {
			for (int j=0;j<26;j++) {
				if (j!=s[i]-'a'&&from[j]<0) {
					bool ok=1;
					int len=0;
					for (int k=j;~k;k=to[k]) {
						len++;
						if (k==s[i]-'a') {
							ok=0;
							break;
						}
					}
					if (!ok&&len<26) {
						continue;
					}
					from[j]=s[i]-'a';
					to[s[i]-'a']=j;
					break;
				}
			}
		}
		t[i]=to[s[i]-'a']+'a';
	}
	cout<<t<<"\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}
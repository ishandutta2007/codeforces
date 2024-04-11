#include <bits/stdc++.h>
using namespace std;

char str[5005];
char s[5005][5005];
int n;

void solve() {
	vector<int> prev;
	for(int i=1;i<=n;i++) {
		prev.push_back(i);
	}
	for(int i=1;i<=n;i++) {
		vector<int> now;
		int mini=1e4;
		for(int j=0;j<prev.size();j++) {
			mini=min(mini,(int)s[prev[j]][i]);
		}
		for(int j=0;j<prev.size();j++) {
			if (s[prev[j]][i]==mini) {
				now.push_back(prev[j]);
			}
		}
		prev.clear();
		for(int j=0;j<now.size();j++) {
			prev.push_back(now[j]);
		}
	}
	for(int i=1;i<=n;i++) {
		printf("%c",s[prev[0]][i]);
	}
	printf("\n%d\n",prev[0]);
}

int mod(int x) {
	if (x==0) {
		return n;
	}
	x=(x-1)%n+1;
	return x;
}

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		scanf("%d\n",&n);
		for(int i=1;i<=n;i++) {
			scanf("%c",&str[i]);
		}
		scanf("\n");
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n-i+1;j++) {
				s[i][j]=str[mod(j+i-1)];
			}
			for(int j=n-i+2;j<=n;j++) {
				if (i%2==n%2) {
					s[i][j]=str[n+1-j];
				}
				else {
					s[i][j]=str[mod(j+i-1)];
				}
			}
		}
		solve();
	}
}
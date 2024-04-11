#include <bits/stdc++.h>
using namespace std;

char str[200001];

int main(void) {
	int tc;
	scanf("%d\n",&tc);
	for(int t=0;t<tc;t++) {
		scanf("%s\n",str);
		int n=strlen(str);
		vector<int> v;
		v.push_back(0);
		for(int i=0;i<n;i++) {
			if (str[i]=='R') {
				v.push_back(i+1);
			}
		}
		v.push_back(n+1);
		int ret=0;
		for(int i=0;i+1<v.size();i++) {
			ret=max(ret,v[i+1]-v[i]);
		}
		printf("%d\n",ret);
	}
}
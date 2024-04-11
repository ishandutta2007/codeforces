#include <bits/stdc++.h>
using namespace std;

char str[1001];
int n;

bool check() {
	int mini=n;
	int maxi=-1;
	for(int i=0;i<n;i++) {
		if (str[i]==')') {
			maxi=max(maxi,i);
		}
		else {
			mini=min(mini,i);
		}
	}
	if (mini>maxi) {
		return true;
	}
	return false;
}

int main(void) {
	scanf("%s",str);
	n=strlen(str);
	if (check()) {
		printf("0");
		return 0;
	}
	printf("1\n");
	int find=0;
	int bind=n-1;
	vector<int> f;
	vector<int> b;
	for(int i=0;i<n;i++) {
		if (str[i]=='(') {
			f.push_back(i);
		}
	}
	for(int i=n-1;i>=0;i--) {
		if (str[i]==')') {
			b.push_back(i);
		}
	}
	vector<int> ret;
	for(int i=0;i<min(f.size(),b.size());i++) {
		if (f[i]<b[i]) {
			ret.push_back(f[i]);
			ret.push_back(b[i]);
		}
		else {
			break;
		}
	}
	printf("%d\n",ret.size());
	sort(ret.begin(),ret.end());
	for(int i=0;i<ret.size();i++) {
		printf("%d ",ret[i]+1);
	}
}
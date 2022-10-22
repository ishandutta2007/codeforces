#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

char s[100001];
char t[100001];

int main(void) {
	int c;
	scanf("%d\n",&c);
	for(int tc=0;tc<c;tc++) {
	    vector<int> v[26];
		scanf("%s\n",s);
		scanf("%s\n",t);
		int sn=strlen(s);
		for(int i=0;i<sn;i++) {
			v[s[i]-'a'].push_back(i);
		}
		int tn=strlen(t);
		int now=-1;
		int cnt=1;
		bool flag=true;
		for(int i=0;i<tn;i++) {
			int p=t[i]-'a';
			if (v[p].empty()) {
				flag=false;
				printf("-1\n");
				break;
			}
			if (upper_bound(v[p].begin(),v[p].end(),now)==v[p].end()) {
			    cnt++;
			    now=-1;
			}
		    now=*upper_bound(v[p].begin(),v[p].end(),now);
		}
		if (flag)
		    printf("%d\n",cnt);
	}
}
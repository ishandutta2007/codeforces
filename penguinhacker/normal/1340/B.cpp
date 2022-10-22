#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const string dig[10]={"1110111", "0010010", "1011101", "1011011", "0111010",
					  "1101011", "1101111", "1010010", "1111111", "1111011"};
int dif(const string &a, const string &b) {
	assert(a.size()==7&&b.size()==7);
	int res=0;
	for (int i=0; i<7; ++i) {
		if (a[i]!=b[i]) {
			if (a[i]>b[i]) return -1;
			++res;
		}
	}
	return res;
}

int n, k, take[2000][2001], pos[2000][2001];
pair<int, int> temp[2001];
string s[2000];

void getPos(int i) {
	vector<int> ind(k+1);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [](int a, int b) {return temp[a]<temp[b];});
	for (int j=0; j<=k; ++j) {
		pos[i][ind[j]]=j;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> s[i];
		fill(take[i], take[i]+k+1, -1);
		//fill(pos[i], pos[i]+k+1, -1);
	}
	fill(temp, temp+k+1, pair<int, int>(-1, -1));
	for (int num=0; num<10; ++num) {
		int x=dif(s[0], dig[num]);
		if (x<=k) {
			take[0][x]=num;
			temp[x]={0, num};
		}
	}
	getPos(0);
	for (int i=1; i<n; ++i) {
		fill(temp, temp+k+1, pair<int, int>(-1, -1));
		for (int j=0; j<=min(k, 7*(i+1)); ++j) {
			for (int num=0; num<10; ++num) {
				int x=dif(s[i], dig[num]);
				if (x==-1||x>j||take[i-1][j-x]==-1) {
					continue;
				}
				pair<int, int> cur={pos[i-1][j-x], num};
				if (cur>temp[j]) {
					take[i][j]=num;
					temp[j]=cur;
				}
			}
		}
		getPos(i);
	}
	if (take[n-1][k]==-1) {
		cout << -1;
		return 0;
	}
	string ans;
	for (int i=n-1, j=k; ~i; --i) {
		assert(take[i][j]!=-1);
		ans.push_back(take[i][j]+'0');
		j-=dif(s[i], dig[take[i][j]]);
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}
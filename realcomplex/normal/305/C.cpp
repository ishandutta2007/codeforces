#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) (((a) < 0) ? (-(a)) : (a))

int main(){
	int n;
	while(cin >> n){
		vector<int>cur;
		int k;
		int ls;
		int v = 0;
		for(int i = 0;i<n;i++){
			cin >> k;
			cur.push_back(k);
			ls = cur.size();
			while(ls >= 2 and cur[ls-1] == cur[ls-2]){
				v = max(v,cur[ls-1]);
				v = max(v,cur[ls-2]);
				cur[ls-2]++;
				cur.pop_back();
				ls = cur.size();
			}
			v = max(v,cur[ls-1]);
		}
		cout << v -cur.size() + 1 << "\n";
	}
	return 0;
}
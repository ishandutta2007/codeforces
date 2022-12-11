#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int N = (int)1e5 + 9;
int ix[N];
int cnt[N];

int main(){
	fastIO;
	int n,m;
	cin >> n >> m;
	int f[n];
	for(int i = 0;i<n;i++){
		cin >> f[i];
		cnt[f[i]]++;
		ix[f[i]] = i+1;
	}
	int b[m];
	bool amb = false;
	for(int j = 0;j<m;j++){
		cin >> b[j];
		if(cnt[b[j]] == 0){
			cout <<"Impossible\n";
			return 0;
		}
		if(cnt[b[j]] != 1)
			amb = true;
	}
	if(amb){
		cout << "Ambiguity\n";
		return 0;
	}
	cout << "Possible\n";
	for(int i = 0;i<m;i++){
		cout << ix[b[i]] << " ";
	}
	cout << "\n";
	return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void NO(){
	cout << "Impossible\n";
	exit(0);
}

const int N = (int)1e5 + 9;
vector<int> ct[N];

int as[N];
int col = 1;

int main(){
	fastIO;
	int n;
	cin >> n;
	int t[n];
	for(int i = 0 ; i <n; i ++ ){
		cin >> t[i];
		t[i] = n - t[i];
		ct[t[i]].push_back(i);
	}
	
	int y;
	for(int i = 1; i <= n; i ++ ){
		while(!ct[i].empty()){
			y = i;
			for(int z =0 ; z <y; z ++ ){
				if(ct[i].empty())
					NO();
				as[ct[i].back()] = col;
				ct[i].pop_back();
			}
			col ++ ;
		}
	}
	for(int i = 0 ; i< n; i ++ ){
		if(as[i] == 0)
			NO();
	}
	cout << "Possible\n";
	for(int i = 0; i < n; i ++ )
		cout << as[i] << " ";
	return 0;
}
#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define SP << " "
#define initrand(x) mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
#define initrand64(x) mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,M;
	cin >> n >> M;
	
	int a[100];
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
		
	map<int,int> m;
	
	cout << "0 ";
	m[a[0]]++;
		
	for (int i = 1; i < n; i++) {	
		int sum = 0;
		int cnt = 0;
		
		for (map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
			if (sum + it->first*it->second <= M-a[i]) {
				sum = sum + it->first*it->second;
				cnt += it->second;
			}
			else {
				int incre = (M-a[i]-sum)/it->first;
				sum = sum + it->first*incre;
				cnt += incre;
				break;
			}
		}
		
		cout << i-cnt << " ";
			
		m[a[i]]++;
	}
					
	return 0;
}
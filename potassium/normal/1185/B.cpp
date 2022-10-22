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
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string s1,s2;
		
		cin >> s1;
		cin >> s2;
		
		int ptr = 0;
		
		bool isOK = 1;
		
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[ptr])
				isOK = 0;
			
			if (s1[i+1] != s1[i])
				while (ptr+1 < s2.length() && s2[ptr+1] == s2[ptr])
					ptr++;
			
			if (ptr >= s2.length()) {
				isOK = 0;
				break;
			}
			
			ptr++;					
		}
		
		if (ptr != s2.length())
			isOK = 0;
		
		if (isOK)
			cout << "YES\n";
		else cout << "NO\n";
	}
					
	return 0;
}
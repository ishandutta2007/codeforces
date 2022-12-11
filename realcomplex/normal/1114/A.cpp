#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void NO(){
	cout << "NO\n";
	exit(0);
}

int main(){
	fastIO;
	int x, y, z;
	int a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	if(x > a)
		NO();
	if(y > a + b - x)
		NO();
	if(x + y + z > a + b + c)
		NO();
	cout << "YES\n";
	return 0;
}
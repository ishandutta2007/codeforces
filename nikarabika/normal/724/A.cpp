//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

string days[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string d1, d2;
	cin >> d1 >> d2;
	int id1 = find(days, days + 7, d1) - days,
		id2 = find(days, days + 7, d2) - days;
	int dist = id2 - id1;
	if(dist < 0) dist += 7;
	if(dist == 0 or dist == 2 or dist == 3)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
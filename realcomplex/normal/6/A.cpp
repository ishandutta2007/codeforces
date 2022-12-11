#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

int check(int x0, int y0, int z0){
	if(x0 + y0 > z0 and y0 + z0 > x0 and x0 + z0 > y0)
		return 1;
	else if(x0 + y0 == z0 or y0 + z0 == x0 or x0 + z0 == y0)
		return 2;
	return 3;
}

int main(){
	fastIO;
	int p[4];
	cin >> p[0] >> p[1] >> p[2] >> p[3];
	sort(p, p + 4);
	bool i1 = false, i2 = false, i3 = false;
	int cond;
	do{
		cond = check(p[0], p[1], p[2]);
		if(cond == 1)
			i1 = true;
		else if(cond == 2)
			i2 = true;
		else
			i3 = true;
	}while(next_permutation(p, p + 4));
	if(i1)
		cout << "TRIANGLE\n";
	else if(i2)
		cout << "SEGMENT\n";
	else
		cout << "IMPOSSIBLE\n";
	return 0;
}
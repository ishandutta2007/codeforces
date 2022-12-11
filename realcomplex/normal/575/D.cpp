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

struct S{
	int x1;
	int x2;
	int y1;
	int y2;
};

int main(){
	vector<S>sear;
	S cur;
	for(int x = 0;x<2;x++)
	for(int i = 2;i<=1000;i++){
		cur.x1 = i;
		cur.x2 = i;
		cur.y1 = 2;
		cur.y2 = 1;
		sear.push_back(cur);
	}
	cout << sear.size() << "\n";
	for(auto x : sear)
		cout << x.x1 << " " << x.y1 << " " << x.x2 << " " << x.y2 << "\n";
	return 0; 
}
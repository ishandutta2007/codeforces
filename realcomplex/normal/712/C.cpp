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

int main(){
	int a,b;
	cin >> a >> b;
	int l1 , l2 , l3;
	l1 = b;
	l2 = b;
	l3 = b;
	int p = 0;
	while(true){
		if(l1 >= a and l2 >= a and l3 >= a){
			cout << p << "\n";
			return 0;
		}
		++p;
		if(p%3==0){
			l1 = l2 + l3 - 1;
		}
		else if(p % 3 == 2){
			l2 = l1 + l3 - 1;
		}
		else{
			l3 = l1 + l2 - 1;
		}
	}
	cout << p << "\n";
	return 0;
}
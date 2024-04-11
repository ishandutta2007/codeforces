#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, m, t, a, b, c, d;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> a >> b;
		cin >> c >> d;
		if (a>= 0 && b>=0){
			cout << min((a+b)*c, min(a,b) * d + c*(max(a,b) - min(a,b))) << "\n";
		}
		else if (a<= 0 && b<=0){
			cout << min((-a-b)*c, -max(a,b) * d + c*(-min(a,b) + max(a,b))) << "\n";
		}
		else {
			cout << (max(a,b) - min(a,b) ) * c << "\n";
		}
		
	}
}
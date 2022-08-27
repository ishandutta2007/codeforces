#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n;
int main(){
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int op = 0, w;
	L(i, 1, n) {
		cin >> w;
		op |= w;
	}
	if(op) cout << "HARD\n";
	else cout << "EASY\n"; 
    return 0;
}
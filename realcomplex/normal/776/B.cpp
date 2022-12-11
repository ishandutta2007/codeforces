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

#define N ((int)1e5 + 9)

bitset<N> pr;

void sieve(){
	for(int i = 2;i<N;i++){
		if(pr[i] == 1)
			continue;
		for(int j = 2;j*i<N;j++){
			pr[i * j] = 1;
		}
	}
}

int main(){
	fastIO;
	sieve();
	int n;
	cin >> n;
	if(n == 1){
		cout << "1 \n 1 \n";
		return 0;
	}
	if(n == 2){
		cout << "1 \n 1 1 \n ";
		return 0;
	}
	cout << 2 << "\n";
	for(int i = 2;i<=n+1;i++){
		cout << pr[i]+1 << " ";
	}
	cout << "\n";
	return 0;	
}
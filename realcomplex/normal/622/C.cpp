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

const int N =(int)2e5 + 9;
int arr[N];
int a[N];

void init(){
	for(int i = 0;i<N;i++)
		a[i] = N;
}

int main(){
	fastIO;
	int n,q;
	cin >>n >> q;
	init();
	for(int i = 1;i<=n;i++)
		cin >> arr[i];
	int l = N;
	for(int i = n-1;i>=1;i--){
		if(arr[i] != arr[i+1]){
			l = i+1;
		}
		a[i] = l;
	}
	int li,ri,xi;
	while(q--){
		cin >> li >> ri >> xi;
		if(arr[li] != xi){
			cout << li << "\n";
		}
		else if(arr[ri] != xi){
			cout << ri << "\n";
		}
		else if(a[li] > ri){
			cout << -1 << "\n";
		}
		else{
			cout << a[li] << "\n";
		}
	}
	return 0;
}
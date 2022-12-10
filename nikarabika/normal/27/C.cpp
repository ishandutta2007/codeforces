#include <bits/stdc++.h>

using namespace std;

#define L first
#define R second

const int maxn = 1e5;
int n;
pair<int, int> a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	if(n < 3){
		cout << 0 << endl;
		return 0;
	}
	int p = 1;
	for(int i = 0; i < n; i++, p++){
		cin >> a[i].L;
		a[i].R = p;
		if(i > 0 and a[i].L == a[i - 1].L)
			i--, n--;
	}
	for(int i = 1; i < n - 1; i++)
		if((a[i] < a[i - 1] and a[i] < a[i + 1]) or (a[i] > a[i - 1] and a[i] > a[i + 1])){
			cout << 3 << endl << a[i - 1].R << ' ' << a[i].R << ' ' << a[i + 1].R << endl;
			return 0;
		}
	cout << 0 << endl;
	return 0;
}
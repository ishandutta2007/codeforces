						/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define P pair<int, int>

int n;
P a[300010];
int res[300010];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	res[a[0].second] = a[0].first;
	for(int i = 1; i < n; i++)
		res[a[i].second] = max(res[a[i - 1].second] + 1, a[i].first);
	for(int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << endl;
	return 0;
}
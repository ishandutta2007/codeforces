#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




 
int main() {
#ifdef HOME
    //ifstream cin("A.in");
    //ofstream cout("A.out");
#endif
    int i, n;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);

    cin >> n;
    vector<int> sums(n + 1);
    for(i = 2; i <= n; i++) {
    	cout << "? " << 1 << " " << i << endl;
    	cin >> sums[i];
    }
   	vector<int> arr(n + 1);
   	for(i = 3; i <= n; i++) {
   		arr[i] = sums[i] - sums[i - 1];
   	}
   	cout << "? 2 3" << endl;
   	int cur;
   	cin >> cur;

   	arr[2] = cur - arr[3];
   	arr[1] = sums[2] - arr[2];

   	cout << "! ";
   	for(i = 1; i <= n; i++) {
   		cout << arr[i] << " ";
   	}
   	cout << endl;
 
    return 0;
}
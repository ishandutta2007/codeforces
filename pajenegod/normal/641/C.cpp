#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <string.h>
#include <set>
#include <math.h>
#include <numeric>
#include <map>
using namespace std;
#define ll long long
const ll inf = 1e9 + 69;
 
int v[1000005];
int n, q;
ll e, o;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n >> q;
	for(int tp, x;q--;){
		cin >> tp;
		if(tp == 1){
			cin >> x;
			e += x; o += x;
		}else{
			e += (!(e & 1)) -(e&1);
			o += (o & 1) -(!(o & 1));
		}
	}
 
	for(int i = 0; i < n; i += 2){
		v[((i + e) % n + n) % n] = i + 1;
	}
	for(int i = 1; i < n; i += 2){
		v[((i + o) % n + n) % n] = i + 1;
	}
 
	for(int i = 0; i < n; i ++)
		cout << v[i] << " ";
}
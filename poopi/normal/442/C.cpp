										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

struct triple{
	int val, idx, sg;
	triple(int v = 0, int i = 0, int s = 0){
		val = v, idx = i, sg = s;
	}
	bool operator < (const triple &x) const{
		if(sg != x.sg)
			return sg > x.sg;
		if(val != x.val)
			return val * sg < x.val * x.sg;
		return idx < x.idx;
	}
};

int n;
int64 arr[500010];
int sg[500010];
set <int> st;
vector <triple> v;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for(int i = 0; i < n; i++){
		sg[i] = 1;
		st.insert(i);
	}
	int mx = 0;
	for(int i = 0; i < n - 1; i++){
		if(arr[i] > mx){
			sg[i] = -1;
			mx = arr[i];
		}
	}
	mx = 0;
	for(int i = n - 1; i > 0; i--){
		if(arr[i] > mx){
			sg[i] = -1;
			mx = arr[i];
		}
	}
	for(int i = 1; i < n - 1; i++)
		if(sg[i] != -1)
			v.push_back(triple(arr[i], i, sg[i]));
	sort(v.begin(), v.end());

	int64 res = 0;
	for(int i = 0; i < v.size(); i++){
		int idx = v[i].idx;
		int bef = *(--st.lower_bound(idx));	
		int nex = *st.upper_bound(idx);
		res += min(arr[bef], arr[nex]);
		st.erase(idx);
		//cout << idx << ' ' << arr[idx] << ' ' << bef << ' ' << nex << ' ' << min(arr[bef], arr[nex]) << endl;
	}
	int p = 0;
	for(int i = 0; i < n; i++)
		if(sg[i] == -1)
			arr[p++] = arr[i];
	n = p;
	int str = 0, end = n - 1;
	//for(int i = 0; i < n; i++)
		//cout << arr[i] << endl;
	while(end - str >= 2){
		if(arr[str] < arr[end])
			res += arr[str++];
		else res += arr[end--];
	}
	cout << res << endl;
	return 0;
}
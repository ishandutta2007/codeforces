#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#define inf (1 << 30)
typedef long long ll;
using namespace std;

int A[100000];
int prec[100001];
vector<pair<int, int>> bases(100000); // def, gold
vector<int> def(100000);

int cmp(pair<int, int> A, pair<int, int> B){
	return A.first < B.first;
}
int main(){
	int n, b;
	cin >> n >> b;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	for(int i=0;i<b;i++){
		int def, gold;
		cin >> def >> gold;
		bases[i] = pair<int, int>{def, gold};
	}
	sort(bases.begin(), bases.begin()+b, cmp);
	prec[0] = 0;
	for(int i=0;i<b;i++){
		prec[i+1] = prec[i] + bases[i].second;
	}
	for(int i=0;i<b;i++){
		def[i] = bases[i].first;
	}
	for(int i=0;i<n;i++){
		int v = A[i];
		int pos = upper_bound(def.begin(), def.begin()+b, v) - def.begin();
		cout << prec[pos] << ' ';
	}
    return 0;
}
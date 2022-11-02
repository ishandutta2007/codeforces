#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
typedef long long ll;
using namespace std;

ll pos, all;
int f(vector<int> & A){
	int len = A.size();
	vector<int> prec(len+1);
	prec[0] = 0;
	for(int i=0;i<len;i++){
		if(A[i] < 0){
			prec[i+1] = prec[i] ^ 1;
		}else{
			prec[i+1] = prec[i];
		}
	}
	ll cnt_0 = count(prec.begin(), prec.end(), 0);
	ll cnt_1 = len + 1 - cnt_0;
	pos += cnt_0 * (cnt_0 - 1) / 2 + cnt_1 * (cnt_1 - 1) / 2;
	all += (ll)len * (len + 1) / 2;
}

int main(){
	int n;
	cin >> n;
	vector<int> A;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		if(v != 0){
			A.push_back(v);
		}else{
			f(A);
			A.clear();
		}
	}
	f(A);
	cout << all - pos << ' ' << pos;
	return 0;
}
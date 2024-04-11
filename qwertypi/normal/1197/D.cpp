#include <iostream>
#include <algorithm>
#include <numeric>
#define inf (1LL << 40)
using namespace std;
typedef long long ll;
int A[300000];
ll n, m, k;

ll cross(int l, int mid, int r){
	ll L[10], R[10];
	fill(L, L + 10, 0);
	fill(R, R + 10, 0);
	ll sum = 0;
    for (int i = mid; i >= l; i--){
        sum = sum + A[i];
        int elem = mid - i + 1;
        L[elem % m] = max(L[elem % m], sum - (ll)k * (elem / m));
    }

    sum = 0;
    for (int i = mid+1; i <= r; i++){
        sum = sum + A[i];
        int elem = i - mid;
        R[elem % m] = max(R[elem % m], sum - (ll)k * (elem / m));
    }
    ll res = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			res = max(res, L[i] + R[j] - (ll)(i + j + m - 1) / m * k);
		}
	}
	return res;
}

ll Sum(int l, int r){
    if(l == r){
		return A[l] - k;
	}
	int mid = (l + r) / 2;
	ll res = max(max(Sum(l, mid), Sum(mid+1, r)), cross(l, mid, r));
	return res;
}

int main(){
	cin >> n >> m >> k;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	cout << max(0LL, Sum(0, n-1));
	return 0;
}
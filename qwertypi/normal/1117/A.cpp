#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
 
ll A[200000];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	int _max = *max_element(A, A+n);
	int ans = 0;
	int curCnt = 0;
	for(int i=0;i<n;i++){
		if(A[i] == _max){
			curCnt++;
		}else{
			ans = max(ans, curCnt);
			curCnt = 0;
		}
	}
	ans = max(ans, curCnt);
	cout << ans;
}
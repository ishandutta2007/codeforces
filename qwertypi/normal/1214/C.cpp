#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p 1000000007

using namespace std;

typedef long long ll;

int A[200001];
int main(){
	int n;
	cin >> n;
	A[0] = 0;
	string s;
	cin >> s;
	for(int i=0;i<n;i++){
		A[i+1] = A[i] + (s[i] == '(' ? 1 : -1);
	}
	if(A[n] == 0 && *min_element(A, A+n+1) >= -1){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <cctype>
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p 1000000007
using namespace std;
typedef long long ll;

char A[100002];
int main(){
	int n;
	cin >> n;
	cin >> A;
	bool State[10];
	fill(State, State + 10, 0);
	for(int i=0;i<n;i++){
		switch(A[i]){
			case 'L':
				for(int i=0;i<10;i++){
					if(State[i] == false){
						State[i] = true;
						break;
					}
				}
				break;
			case 'R':
				for(int i=9;i>=0;i--){
					if(State[i] == false){
						State[i] = true;
						break;
					}
				}
				break;
			default:
				State[A[i] - '0'] = 0;
		}
	}
	for(int i=0;i<10;i++){
		cout << (char)('0' + (int)State[i]);
	}
	return 0;
}
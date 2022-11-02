#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

vector<set<int>> Groups;
int A[200000];
int B[200000];
char ans[200002];
int main(){
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	for(int i=0;i<n;i++){
		cin >> B[i];
	}
	set<int> set_K;
	int curCnt = 0;
	for(int i=0;i<n;i++){
		set_K.insert(A[i]);
		set_K.insert(B[i]);
		curCnt++;
		if(set_K.size() == curCnt){
			curCnt = 0;
			Groups.push_back(set_K);
			set_K.clear();
		}
	}
	if(Groups.size() < k){
		cout << "NO";
	}else{
		cout << "YES" << endl;
		char alpha = 'a';
		for(auto _s : Groups){
			for(auto I : _s){
				ans[I-1] = alpha;
			}
			alpha = (char)min(alpha + 1, (int)'z');
		}
		ans[n] = '\0';
		cout << ans;
	}
}
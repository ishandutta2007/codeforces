								/* in the name of Allah */
#include <iostream>
using namespace std;

int n, k;
int arr[1010];
int res[1010];
bool mark[1010];

int main(){
	while(cin >> n >> k){
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		for(int i = 0; i < n; i++){
			int p = 0;
			while(mark[p] || arr[p] > 0)
				p++;
			res[i] = p + 1;
			mark[p] = true;
			for(int j = 0; j + k <= p; j++)
				arr[j]--;
		}
		for(int i = 0; i < n; i++){
			if(i > 0) cout << ' ';
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}
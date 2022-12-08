								/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

int n;
int arr[100010];

int main(){
	while(cin >> n){
		for(int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		arr[n++] = 1000000001;
		long long res = 0, cnt = 0;
		for(int i = 0; i < n; i++){
			if(i != 0 && arr[i] != arr[i - 1]){
				res += cnt * (cnt + 1) / 2;
				cnt = 0;
			}
			cnt++;
		}
		cout << res << endl;
	}
	return 0;
}
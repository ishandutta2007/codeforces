										/* in the name of Allah */
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int n;
int arr[100010];

int gd(int str){
	int cnt = 0;
	if(arr[str] == 0){
		for(int i = str + 1; i < n; i++)
			if(arr[i] != 0) cnt++;
		return min(cnt, 2);
	}
	for(int i = str + 1; i + 1 < n && cnt < 2; i++){
		if(arr[str] * arr[i + 1] != arr[str + 1] * arr[i]){
			cnt++;
			if(i + 2 < n && arr[str] * arr[i + 2] != arr[str + 1] * arr[i])
				cnt++;
			i++;
		}
	}
	return min(cnt, 2);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
/*	if(n == 2){
		if(arr[0] == 0 && arr[1] != 0)
			cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}*/
	int t1 = gd(0);
	int t2 = gd(1);
	arr[1] = arr[0];
	int t3 = gd(1);
	if(t1 == 0)
		cout << 0 << endl;
	else if(t1 == 1 || t2 == 0 || t3 == 0)
		cout << 1 << endl;
	else cout << 2 << endl;
	return 0;
}
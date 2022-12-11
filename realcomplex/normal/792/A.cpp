#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
	int n;
	cin >> n;
	int sk[n];
	for(int i = 0;i<n;i++){
		cin >> sk[i];
	}
	sort(sk,sk + n);
	int distance = 2000000000;
	int times = 0;
	for(int i = 1;i<n;i++){
		if(sk[i] - sk[i - 1] < distance){
			distance = sk[i] - sk[i - 1];
		}
	}
	for(int i = 1;i<n;i++){
		if(sk[i] - sk[i - 1] == distance){
			times++;
		}
	}
	cout << distance << " " << times; 
	return 0;
}
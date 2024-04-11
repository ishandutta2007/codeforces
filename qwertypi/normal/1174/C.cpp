#include <iostream>
#include <numeric>
using namespace std;
bool isPrime[100001];

void primeGenerate(){
	int i=2;
	while(i * i <= 100000){
		if(!isPrime[i]){
			i++;
			continue;
		}
		for(int j=2; i * j <= 100000;j++){
			isPrime[i*j] = 0;
		}
		i++;
	}
}

int A[100001];
int main(){
	fill(isPrime+2, isPrime+100000, 1);
	primeGenerate();
	int n;
	cin >> n;
	int cnt = 1;
	for(int i=2;i<=n;i++){
		if(isPrime[i]){
			for(int j = 1; i * j <= n; j++){
				A[i * j] = cnt;
			}
			cnt++;
		}
	}
	for(int i=2;i<=n;i++){
		cout << A[i] << ' ';
	}
	return 0;
}
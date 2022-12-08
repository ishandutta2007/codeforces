							/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

#define P pair<int, int>

int n, w;
P num[110];

int main(){
	int sum = 0;
	cin >> n >> w;
	for(int i = 0; i < n; i++){
		cin >> num[i].first;
		sum += num[i].first;
		num[i].first *= 2;
		num[i].second = i + 1;
	}
	if(n == 1){
		if(2 * w != num[0].first)
			cout << "No" << endl;
		else{
			cout << "Yes" << endl;
			for(int i = 0; i < num[0].first; i++){
				if(i > 0)
					printf(" ");
				printf("1");
			}
			printf("\n");
		}
		return 0;
	}
	if(w < 1 || w > sum){
		cout << "No" << endl;
		return 0;
	}
	sort(num, num + n);
	if(num[0].first > 2 * w && w == 1){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	if(num[0].first > 2 * w){
		printf("%d ", num[1].second);
		while(num[0].first > 2 * (w - 1)){
			printf("%d ", num[0].second);
			num[0].first--;
		}
		printf("%d ", num[1].second);
		num[1].first -= 2;
		w--;
	}
	sum = 0;
	for(int i = 0; i < n; i++)
		sum += num[i].first / 2;
	int str = 0, end = n - 1;
	printf("%d", num[str].second);
	num[str].first--;
	for(int i = 0; i < 2 * (sum - w); i++){
		while(num[end].first == 0)
			end--;
		num[end].first--;
		printf(" %d", num[end].second);
	}
	for(int i = 0; i < 2 * w - 1; i++){
		while(num[str].first == 0)
			str++;
		num[str].first--;
		printf(" %d", num[str].second);
	}
	printf("\n");
	return 0;
}
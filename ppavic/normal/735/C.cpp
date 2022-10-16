#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

long long int n;

int main(){
	cin >> n;
	long long int i = 1;
	long long int last = 1,cur = 1,tmp;
	while(cur <= n){
		tmp = cur;
		cur = cur + last;
		last = tmp;
		i++;
	}
	i-=2;
	cout << i << endl;
}
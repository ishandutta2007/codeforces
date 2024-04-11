#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
double n1,n2,tmp;
double a[100005];
double sum1 = 0,sum2 = 0;

int main(){
	cin >> n;
	cin >> n1 >> n2;
	if(n1 > n2){
		tmp = n1;
		n1 = n2;
		n2 = tmp;
	}
	double o1 = n1,o2 = n2;
	for(int i = 0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	int i;
	for(i = n-1;n1 > 0;i--,n1--){
		sum1 += a[i];
	}
	for(;n2 > 0;i--,n2--){
		sum2 += a[i];
	}
	printf("%f\n",sum2/o2+sum1/o1);
}
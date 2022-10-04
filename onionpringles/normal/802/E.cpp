#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[250];
int cnt[2001];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++){
		int N = 250;
		for(int j=0;j<N;j++)scanf("%d",a+j);
		double M=0;
		for(int j=0;j<N;j++)M+=a[j];
		M/=N;
		double v=0;
		for(int j=0;j<N;j++)v += (a[j]-M)*(a[j]-M);
		v /= N;
		if(v < 3*M){
			printf("%d\n",(int)round(M));
		}
		else {
			printf("%d\n",(*max_element(a,a+N)+*min_element(a,a+N))/2);
		}
	}
}
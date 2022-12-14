#include<bits/stdc++.h>
using namespace std;


int n;
vector<long long int> v;
int main(){
	cin >> n;
	for (int i = 0; i < 2*n; i++){
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	long long int out2 = LLONG_MAX;
	for (int i = 1; i < v.size(); i++){
		int lef = i;
		int rig = i + n;
		rig--;
		if (rig+1 < v.size()){
			out2 =min(out2, (v[rig] - v[lef])*(v.back() - v[0]));
		}
	}
	n *= 2;
	long long int ans = v[(n-1) / 2] - v[0];
	long long int ans2 = v.back() - v[n / 2];
	printf("%lld\n", min(out2,ans*ans2));
	return 0;
}
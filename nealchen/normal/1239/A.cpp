#include <iostream>
const int P=1e9+7;
int f[100005];
int main() {
	int n, m, ans=2;
	std::cin>>n>>m;
	f[0]=f[1]=1;
	for(int i=2; i<=n||i<=m; ++i) f[i]=(f[i-2]+f[i-1])%P;
	std::cout<<((long long)f[n]+f[m]+P-1)*2%P;
	return 0;
}
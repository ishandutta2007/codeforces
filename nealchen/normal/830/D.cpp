#include <iostream>
#include <cstring>
const int P=1e9+7;
int n, f[412], g[412];
int main()
{
	int i, j, k;
	std::cin >> n;
	f[0]=f[1]=1;
	for(i=2; i<=n; ++i) {
		memset(g, 0, (n-i+3)*sizeof(int));
		for(j=0; j<=n-i+2; ++j) {
		    for(k=0; k<=n-i+2-j; ++k)
		        g[j+k]=(g[j+k]+1llu*f[j]*f[k])%P;
		}
		f[0]=1;
		for(j=1; j<=n-i+1; ++j)
		    f[j]=(g[j-1]+(2llu*j+1)*g[j]+j*(j+1llu)*g[j+1])%P;
	}
	std::cout << f[1];
	return 0;
}
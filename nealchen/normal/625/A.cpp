#include <iostream>
int main() {
	long long n, a, b, c, ans=0;
	std::cin>>n>>a>>b>>c;
	if(b-c<a&&n>=b) {
		ans=(n-c)/(b-c);
		n-=ans*(b-c);
	}
	std::cout<<ans+n/a;
	return 0;
}
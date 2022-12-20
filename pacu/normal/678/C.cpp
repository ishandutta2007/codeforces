#include <iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	long long N,A,B,P,Q;
	cin >> N >> A >> B >> P >> Q;
	long long lcm = (A*B)/gcd(A,B);
	long long ans = P*((N/A) - (N/lcm)) + Q*((N/B) - (N/lcm)) + max(P,Q)*(N/lcm);
	cout << ans << '\n';
}
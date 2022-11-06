#include <iostream>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long Mod = 1;
    for(;n--;){
		Mod *= 2;
		if(Mod > m) break;
    }
    printf("%lld\n", m % Mod);
    return 0;
}
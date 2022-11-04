#include <iostream>

int main()
{
        long long n, k;
        std::cin >> n >> k;
        long long c = (n / 2) / (k + 1), d = c * k, w = n - c - d;
        std::cout << c << " " <<  d << " " << w << std::endl;
        return 0;
}
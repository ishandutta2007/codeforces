#include <bits/stdc++.h>
using namespace std;

int TC;
long long A, B, P, Q;

// C++ program to find multiplicative modulo inverse using
// Extended Euclid algorithm.
#include<iostream>
using namespace std;
 
// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y);
 
// Function to find modulo inverse of a
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        return res;
    }
}
 
// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int main() {
	scanf("%d", &TC);
	while (TC--) {
		scanf("%lld%lld%lld%lld", &A, &B, &P, &Q);
		long long bot = -1, top = 1500000000, mid;
		while (bot + 1 < top) {
			mid = (bot + top) / 2;
			long long actP = P * mid, actQ = Q * mid;
			long long diff = actQ - B;
			long long diffN = actP - A;
			//printf("%lld: %lld, %lld\n", mid, diffN, diff);
			if (diffN >= 0 && diffN <= diff) top = mid;
			else bot = mid;
		}
		if (bot + 1 >= 1500000000) printf("-1\n");
		else printf("%lld\n", (bot + 1) * Q - B);
	}
		
}
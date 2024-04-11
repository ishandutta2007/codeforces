#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>

typedef long long ll;
typedef double ld;

#define pb push_back
#define mp make_pair

using namespace std;


const int MAX_N = 2e6 + 7;
const long long MOD = 1e9 + 7;

long long fact[MAX_N];
long long sub_fact[MAX_N];
long long rev[MAX_N];
long long rev_fact[MAX_N];

void pre_calc() {
    fact[0] = fact[1] = 1;
    sub_fact[0] = sub_fact[1] = 1;
    rev[0] = rev[1] = 1;
    rev_fact[0] = rev_fact[1] = 1;
    for (int i = 2; i < MAX_N; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
        sub_fact[i] = (i * sub_fact[i - 2]) % MOD;
        rev[i] = (MOD - ((MOD / i) * rev[MOD % i]) % MOD);
        rev_fact[i] = (rev_fact[i - 1] * rev[i]) % MOD;
    }
}

long long C(int n, int k) {
    return ((fact[n] * rev_fact[k]) % MOD * rev_fact[n - k]) % MOD;
}


int main()
{
	long long n, ans = 0, cur = 1;
	cin >> n;
	n++;
	pre_calc();
	cout << (C(2 * n, n) - 1 + MOD) % MOD;
}
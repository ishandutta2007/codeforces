#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    int k2,k3,k5,k6;
    cin >> k2 >> k3 >> k5 >> k6;
    int a256 = min(k2,min(k5,k6));
    k2-=a256;
    k5-=a256;
    k6-=a256;
    int sum = a256*256;
    sum += min(k2,k3)*32;
    cout << sum;
    return 0;
}
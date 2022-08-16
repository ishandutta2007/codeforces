#include <bits/stdc++.h>
using namespace std;
#define f(n) for(int I=0;I<n;I++)
int main()
{
int a[4];

f(4) cin >> a[I];
sort(a,a+4);
f(3) cout << a[3]-a[I] << " ";

}
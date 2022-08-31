#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin >> n;

int a[n];


for(int i=0;i<n;i++)
{
    cin >> a[i];
}

sort(a,a+n);

cout << min(abs(a[n-2]-a[0]),abs(a[n-1]-a[1]));
return 0;
}
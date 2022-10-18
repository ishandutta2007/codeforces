#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	int n;
	cin >> n;
	int maxx = 0, sum = 0;
	for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        maxx = max(maxx, k);
        sum += k;
    }
    cout << maxx * n - sum;
	return 0;
}
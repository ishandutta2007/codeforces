#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int mint;

mint arr[100001] = { 0, };
mint arr1[100001] = { 0, };
mint darr[100001] = { 0, };
mint darr1[100001] = { 0, };
mint delarr[100001] = { 0, };
mint delarr1[100001] = { 0, };

int main()
{
	mint n;
	cin >> n;
	for (mint i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr1[i] = arr[i];
	}
	for (mint i = 2; i <= n; i++)
	{
		darr[i] = darr[i - 1];
		if (arr[i] <= arr[i - 1])
		{
			darr[i] += arr[i - 1] - arr[i] + 1;
			arr[i] = arr[i - 1] + 1;
		}
		delarr[i] = darr[i] - darr[i - 1];
	}
	for (mint i = n - 1; i >= 1; i--)
	{
		darr1[i] = darr1[i + 1];
		if (arr1[i] <= arr1[i + 1])
		{
			darr1[i] += arr1[i + 1] - arr1[i] + 1;
			arr1[i] = arr1[i + 1] + 1;
		}
		/*while (arr1[i] <= arr1[i + 1])
		{
			arr1[i]++;
			darr1[i]++;
		}*/
		delarr1[i] = darr1[i] - darr1[i + 1];
	}
	mint ans = 200000000000000;
	for (mint i = 1; i <= n; i++)
		if (darr[i] + darr1[i] - min(delarr[i], delarr1[i]) < ans)
			ans = darr[i] + darr1[i] - min(delarr[i], delarr1[i]);
	cout << ans;
	return 0;
}
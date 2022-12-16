//IO
#include <iostream>
#include <cstdio>
#include <iomanip>

//General
#include <cmath>
#include <cstdlib>
#include <cstring>

//STL
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N;
struct Node
{
	int val;
	int no;
} A[10000];

bool operator < (const Node &a, const Node &b)
{
	return a.val < b.val;
}

int main ()
{
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i].val;
		A[i].no = i + 1;
	}
	sort (A, &A[N]);
	for (int i = 0; i < N / 2; i++)
		cout << A[i].no << " " << A[N - i - 1].no << endl;
	return 0;
}
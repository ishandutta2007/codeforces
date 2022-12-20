#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	long long k,n,w;
	cin >> k >> n >> w;
	long long cost = (w*(w+1)*k)/2LL;
	cout << max(cost-n,0LL) << endl;
}
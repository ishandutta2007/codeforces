#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <complex>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

#pragma comment(linker,"/STACK:200000000")

using namespace std;

const bool interactive = false;
const string filename = "records";
const double pi = 3.14159265358979323846;
const int inf = int (1e9) + 7;
const long long linf = (long long) 1e18 + 9;

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);

    int k, n;

    cin >> n >> k;

    vector<int> arr (n);

    for (int i = 0; i < arr.size (); i++)
        cin >> arr[i];

    sort (arr.begin (), arr.end (), greater<int> ());

    int pos = k;

    while (pos < arr.size () && arr[pos] == arr[pos - 1])
        pos++;

    while (pos > 0 && arr[pos - 1] == 0)
        pos--;

    cout << pos << endl;

    return 0;
}
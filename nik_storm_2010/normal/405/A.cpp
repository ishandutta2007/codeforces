#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector <int> a;

int main()
{
    ios_base::sync_with_stdio(true);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
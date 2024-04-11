#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long ost = 0;
    for (int i = 0; i < n; ++i){
        ost += a[i];
        cout << ost / m<< " ";
        ost = ost % m;
    }
    return 0;
}
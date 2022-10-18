#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int k; cin >> k;
    int a[12];
    for (int i=0; i<12; i++) cin >> a[i];
    sort(a,a+12);
    int res = 0;
    for (int i=11; i>=0; i--)
    {
     if (res >= k) { cout << 11-i << endl; return 0; };
     res+=a[i];
    }
     if (res >= k) { cout << 12 << endl; return 0; };
    cout << "-1" << endl;
    return 0;
}
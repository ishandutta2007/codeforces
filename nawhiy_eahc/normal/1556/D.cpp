#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[10002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    int o1, o2, o3;
    int a1, a2, a3;
    cout << "or 1 2" << endl;
    cin >> o1;
    cout << "or 2 3" << endl;
    cin >> o2;
    cout << "or 1 3" << endl;
    cin >> o3;
    cout << "and 1 2" << endl;
    cin >> a1;
    cout << "and 2 3" << endl;
    cin >> a2;
    cout << "and 1 3" << endl;
    cin >> a3;

    a[1] = a1 | a3;
    int tmp = (o1 & o3);
    for(int i=0;i<31;i++)
    {
        if(((1<<i) & tmp) && !((1<<i) & o2)) a[1] |= (1<<i);
    }

    a[3] = a2 | a3;
    tmp = (o2 & o3);
    for(int i=0;i<31;i++)
    {
        if(((1<<i) & tmp) && !((1<<i) & o1)) a[3] |= (1<<i);
    }

    a[2] = a1 | a2;
    tmp = (o1 & o2);
    for(int i=0;i<31;i++)
    {
        if(((1<<i) & tmp) && !((1<<i) & o3)) a[2] |= (1<<i);
    }

    for(int i=4;i<=n;i++)
    {
        int A, O;
        cout << "or 1 " << i << endl;
        cin >> O;
        cout << "and 1 " << i << endl;
        cin >> A;
        a[i] = A + O - a[1];
    }

    sort(a + 1, a + n + 1);
    cout << "finish " << a[k] << endl;
}
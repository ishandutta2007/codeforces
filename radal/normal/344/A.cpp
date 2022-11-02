#include <iostream>
using namespace std;
int main()
{
    int n, p, g=1;
    cin>>n>> p;
    int c=p;
    for (int i = 1; i < n; i++)
    {
        cin >> p;
        if (p!=c)
        {
            c=p;
            g++;
        }
    }
    cout<<g;
}
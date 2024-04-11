#include <iostream>

using namespace std;

int N;
string a = "1", b = "1", q;
int aa, bb;

int main()
{
    cin >> N;
    int i;
    for(i = 0; i < N; ++i)
    {
        cin >> q;
        if(q == a)
        {
            ++aa;
        }
        else if(q == b)
        {
            ++bb;
        }
        else if(a == "1")
        {
            a = q;
            ++aa;
        }
        else if(b == "1")
        {
            b = q;
            ++bb;
        }
    }
    if(aa > bb)
    {
        cout << a;
    }
    else
    {
        cout << b;
    }
    return 0;
}
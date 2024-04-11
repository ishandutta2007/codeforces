#include <iostream>

using namespace std;

int N;
int a[3001];

int main()
{
    int q = 1;
    cin >> N;
    int i;
    for(i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    bool ex = false;
    while(ex == false)
    {
        ex = true;
        for(i = 0; i < N; ++i)
        {
            if(q == a[i])
            {
                ++q;
                ex = false;
            }
        }
    }
    cout << q;
    return 0;
}
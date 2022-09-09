#include <iostream>

using namespace std;

int N;

int main()
{
    cin >> N;
    int k = 0;
    for(int i = 0; i < N - 1; ++i)
    {
        k = (k + i + 1) % N;
        cout << k + 1 << " ";
    }
    return 0;
}
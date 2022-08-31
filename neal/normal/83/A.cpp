#include <iostream>
using namespace std;

const int MAXN = 100005;

int N, a [MAXN];

int main ()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> a [i];

    long long magic = 0;

    for (int i = 0, j = 0; i < N; i = j)
    {
        while (j < N && a [i] == a [j])
            j++;

        magic += (long long) (j - i + 1) * (j - i) / 2;
    }

    cout << magic << '\n';
    return 0;
}
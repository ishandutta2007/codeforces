#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <int> seq;

bool geom (vector <int> v)
{
    int n = v.size ();

    for (int i = 0; i + 1 < n; i++)
        if (v [i] == 0 && v [i + 1] != 0)
            return false;

    for (int i = 1; i + 1 < n; i++)
        if (v [i] * v [i] != v [i - 1] * v [i + 1])
            return false;

    return true;
}

bool test (const vector <int> &v, int val, int mult)
{
    int n = v.size (), skip = 0;

    for (int i = 0; i < n; i++)
        if (v [i] == val)
            val = mult * val;
        else
            skip++;

    return skip <= 1;
}

int main ()
{
    cin >> N;
    seq.resize (N);

    for (int i = 0; i < N; i++)
        cin >> seq [i];

    if (geom (seq))
    {
        cout << "0\n";
        return 0;
    }

    if (N <= 15)
    {
        for (int i = 0; i < N; i++)
        {
            vector <int> v;

            for (int j = 0; j < N; j++)
                if (i != j)
                    v.push_back (seq [j]);

            if (geom (v))
            {
                cout << "1\n";
                return 0;
            }
        }
    }
    else
    {
        int num;

        if (abs (seq [0]) == abs (seq [1]))
            num = abs (seq [0]);
        else if (abs (seq [1]) == abs (seq [2]))
            num = abs (seq [1]);
        else if (abs (seq [2]) == abs (seq [0]))
            num = abs (seq [2]);
        else
        {
            cout << "2\n";
            return 0;
        }

        if (test (seq, num, 1) || test (seq, -num, 1) || test (seq, num, -1) || test (seq, -num, -1))
        {
            cout << "1\n";
            return 0;
        }
    }

    cout << "2\n";
    return 0;
}
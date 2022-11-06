#include <iostream>

using namespace std;

int find(int a)
{
    int primes[24];
    fill(primes, primes + 24, 0);
    for (int i = 2; i <= a; i++)
    {
        while (a % i == 0)
        {
            primes[i]++;
            a /= i;
        }
    }
    int ans = 0;
    if (primes[23] == 1)
    {
        ans |= (1 << 4);
    }
    if (primes[7] == 1)
    {
        ans |= (1 << 5);
        primes[2]--;
    }
    if (primes[5] == 1)
    {
        ans |= (1 << 2);
    }
    if (primes[2] == 2)
    {
        ans |= (1 << 0);
    }
    if (primes[2] == 3)
    {
        ans |= (1 << 1);
    }
    if (primes[2] == 4)
    {
        ans |= (1 << 3);
    }
    if (primes[2] == 5)
    {
        ans |= (1 << 0);
        ans |= (1 << 1);
    }
    if (primes[2] == 6)
    {
        ans |= (1 << 0);
        ans |= (1 << 3);
    }
    if (primes[2] == 7)
    {
        ans |= (1 << 1);
        ans |= (1 << 3);
    }
    return ans;
}

int getIndex(int bitset)
{
    for (int i = 0; i < 30; i++)
    {
        if ((bitset & (1 << i)) > 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int key[6] = {4, 8, 15, 16, 23, 42};

    int* sol = new int[7];
    int* q = new int[5];
    int* bitsets = new int[5];
    for (int i = 1; i <= 4; i++)
    {
        cout << "? " << i << " " << (i + 1) << endl;
        fflush(stdout);
        cin >> q[i];
        bitsets[i] = find(q[i]);
    }

    sol[1] = key[getIndex(bitsets[1] & (~bitsets[2]))];
    sol[2] = key[getIndex(bitsets[1] & bitsets[2])];
    sol[3] = key[getIndex(bitsets[2] & bitsets[3])];
    sol[4] = key[getIndex(bitsets[3] & bitsets[4])];
    sol[5] = key[getIndex(bitsets[4] & (~bitsets[3]))];
    sol[6] = key[getIndex(~(bitsets[1] | bitsets[2] | bitsets[3] | bitsets[4]))];
    cout << "! ";
    for (int i = 1; i <= 6; i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;
    fflush(stdout);

    return 0;
}
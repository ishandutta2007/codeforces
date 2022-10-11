#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
typedef unsigned __int128 u128;
 
const array<char, 16>bitreverse = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
 
#define getchar _getchar_nolock
int readint()
{
    int x = 0;
    char c;
    while ((c = getchar()) >= '0')
        x = 10 * x + c - '0';
    return x;
}
 
int conv(int x)
{
    if (x <= '9')
        return x - '0';
    else
        return x - 'A' + 10;
}

bool checker(array<u128, 64> &A, array<u128, 64> &B)
{
    for (int i = 0; i < A.size(); ++i)
        if (~A[i] & B[i])
            return true;
    return false;
}

int main()
{
    int n = readint();
    int upper = (n + 127) / 128;
  
    vector<vector<char>> A(n);
    for (auto &a : A)
    {
        for (int i = 0; i < n/4; ++i)
        {
            char c = getchar();
            a.push_back(bitreverse[conv(c)]);
        }
        getchar();
    }
 
 
    vector<int> order(n / 4);
    for (int i = 0; i < n / 4; ++i)
        order[i] = i;
 
    random_shuffle(order.begin(), order.end());
    
    // vectors of bitsets
    vector<array<u128, 64>> coupl(n);
    for (int i = 0; i < n; ++i)
    {
        vector<char> &Ai = A[4 * order[i >> 2] + (i & 3)];
        auto &B = coupl[i];
        for (int j = 0; j < upper; ++j)
        {
            u128 x = 0;
            for (int k = j << 5; k < min((j + 1 << 5), n >> 2); ++k)
                x += (u128)Ai[order[k]] << (u128)(4 * (k & 31));
            B[j] = x;
        }
    }

    // count set bits in bitset
    vector<int> bitcounter(1);
    for (int i = 1; i < 65536; ++i)
        bitcounter.push_back(bitcounter[i & i - 1] + 1);
 
    vector<int> count;
    for (int i = 0; i < n; ++i)
    {
        int total = 0;
        for (auto &c : coupl[i])
            total += bitcounter[(c >> 0  ) & 65535] + 
                     bitcounter[(c >> 16 ) & 65535] + 
                     bitcounter[(c >> 32 ) & 65535] + 
                     bitcounter[(c >> 48 ) & 65535] +
                     bitcounter[(c >> 64 ) & 65535] + 
                     bitcounter[(c >> 80 ) & 65535] + 
                     bitcounter[(c >> 96 ) & 65535] +
                     bitcounter[(c >> 112) & 65535];
        count.push_back(total);
    }
 
    long long onepairs = n * (n - 1) / 2;
    long long twopairs = 0;
 
    vector<int> nodes(n);
    for (int i = 0; i < n; ++i)
        nodes[i] = i;
    
    // some superfast n log n prework to remove all nodes with infinite distance (same first step as in the intended solution)
    sort(nodes.begin(), nodes.end(), [&](int a, int b){return count[a] < count[b];});
    long long infpairs = 0;
    while (nodes.size() > 0 && count[nodes[nodes.size()-1]] == nodes.size() - 1)
    {
        nodes.pop_back();
        infpairs += nodes.size();
    }
 
    // Do the raw n^3/64 work
    sort(nodes.begin(), nodes.end()); 
    while (nodes.size() > 0)
    {
        int root = nodes.back();
        nodes.pop_back();
        auto &C1 = coupl[root];
        for (auto node : nodes)
        {
            auto &C2 = coupl[node];
            if (C1[node >> 7] >> (node & 127) & 1)
            {
                twopairs += checker(C1, C2);
            } else {
                twopairs += checker(C2, C1);
            }
        }
    }
    long long threepairs = n * (n - 1) - onepairs - twopairs - infpairs;
 
    cout << onepairs + 2 * twopairs + 3 * threepairs + 614 * n * infpairs; 
}
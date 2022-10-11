#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

uint A,B,C,D;
uint ans;
uint n;

void count(uint p)
{
    uint count = 0;
    uint m = n;
    while (m >= p)
    {
        count += (m /= p);
    }
    ans += count * (((A * p + B) * p + C) * p + D);
}
 
const int MAXPR = (int)3e8;
void calcPrimes() {
    count(2);
    const int S = round(sqrt(MAXPR));
    vector<char> sieve(S + 1, true);
    vector<array<int, 2>> cp;
    for (int i = 3; i < S; i += 2) {
        if (!sieve[i])
            continue;
        cp.push_back({i, i * i /2});
        for (int j = i * i; j <= S; j += 2 * i)
            sieve[j] = 0;
    }
    vector<char> block(S);
    int high = (MAXPR - 1) / 2;
    for (int low = 0; low <= high; low += S) {
        fill(block.begin(), block.end(), 1);
        for (auto &i : cp) {
            int p = i[0], idx = i[1];
            for (; idx < S; idx += p)
                block[idx] = 0;
            i[1] = idx - S;
        }
        if (low == 0)
            block[0] = 0;
        for (int i = 0; i < S && low + i <= high; i++)
            if (block[i])
                count((low + i) * 2 + 1);
    };
}
 
int main() {
    cin >> n >> A >> B >> C >> D;
    calcPrimes();
    cout << ans;
	return 0;
}
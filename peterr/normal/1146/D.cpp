#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1E9;
const int MAXA = 1E5;
vector<int> order;
bool visited[MAXA];

int main()
{
    int m, a, b;
    cin >> m >> a >> b;
    int mod = a % b;
    while (!visited[mod])
    {
        visited[mod] = true;
        int n = (a - mod + (b - 1)) / b;
        order.push_back(n * b + mod);
        mod = (a + mod) % b;
    }
    int x = 1;
    int index = 0;
    long long ans = 0;
    fill(visited, visited + MAXA, false);
    int countt = 0;
    while (x <= m && index < order.size())
    {
        if (x == order[index])
        {
            while (index < order.size() && x >= order[index])
            {
                int n = (x - order[index] % b) / b;
                countt += n + 1;
                if (order[index] % b == 0)
                    countt--;
                visited[order[index++] % b] = true;
            }
        }
        else if (visited[x % b])
        {
            countt++;
        }
        ans += countt;
        x++;
    }
    while (x <= m && x % b != 0)
    {
        if (visited[x % b])
            countt++;
        ans += countt;
        x++;
    }
    //int rem = m - x + 1;
    //ans += (long long) countt * rem;
    int gcd = __gcd(a, b);
    int cycles = (m - x + 1) / gcd;
    ans += gcd * (((long long) cycles * (cycles + 1)) / 2);
    ans += (long long) countt * cycles * gcd;
    x += cycles * gcd;
    while (x <= m)
    {
        ans += x / gcd;
        x++;
    }
    cout << ans + m + 1 << endl;
    return 0;
}
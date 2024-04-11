#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

const int MAX_RUN = 20000;

void reduce(int& rise, int& run, vector<int> &primes)
{
    if (rise * run < 0 && rise > 0 || rise * run > 0 && rise < 0)
    {
        rise *= -1;
        run *= -1;
    }

    if (rise == 0)
        run = 1;
    else if (run == 0)
        rise = 1;
    else
    {
        int i = 0;
        while (i < primes.size() && primes[i] <= run)
        {
            while (rise % primes[i] == 0 && run % primes[i] == 0)
            {
                rise /= primes[i];
                run /= primes[i];
            }
            i++;
        }
    }
}

int main()
{
    bool isPrime[MAX_RUN + 1];
    vector<int> primes;
    fill(isPrime, isPrime + MAX_RUN + 1, true);
    for (int i = 2; i < MAX_RUN + 1; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
            for (int j = 2 * i; j < MAX_RUN + 1; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    int* x = new int[n];
    int* y = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        cin >> y[i];
    }

    unordered_map<string, int> slopeCount;
    unordered_set<string>* prevSlope = new unordered_set<string>[n];
    for (int i = 0; i < n; i++)
    {
        for (int j =  i + 1; j < n; j++)
        {
            int rise = y[i] - y[j];
            int run = x[i] - x[j];
            reduce(rise, run, primes);
            string slope = to_string(rise) + ":" + to_string(run);
            if (prevSlope[i].find(slope) == prevSlope[i].end())
            {
                if (slopeCount.find(slope) == slopeCount.end())
                {
                    slopeCount[slope] = 1;
                }
                else
                {
                    slopeCount[slope]++;
                }
            }
            prevSlope[i].insert(slope);
            prevSlope[j].insert(slope);
        }
    }

    long long sum = 0;
    long long sol = 0;
    for (auto it = slopeCount.begin(); it != slopeCount.end(); it++)
    {
        sol += it->second * sum;
        sum += it->second;
    }
    cout << sol;

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

long double VERT = 1e5;

int main()
{
    int n;
    cin >> n;
    int* x = new int[n];
    int* y = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    unordered_map<long double, int> slopeFreq;
    unordered_set<long double>* prevSlope = new unordered_set<long double>[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long double slope;
            if (x[i] == x[j])
            {
                slope = VERT;
            }
            else
            {
                slope = (long double) (y[i] - y[j]) / (x[i] - x[j]);
            }

            if (prevSlope[i].find(slope) == prevSlope[i].end())
            {
                if (slopeFreq.find(slope) == slopeFreq.end())
                {
                    slopeFreq[slope] = 1;
                }
                else
                {
                    slopeFreq[slope]++;
                }
            }

            prevSlope[i].insert(slope);
            prevSlope[j].insert(slope);
        }
    }

    long long sum = 0;
    long long sol = 0;
    for (auto it = slopeFreq.begin(); it != slopeFreq.end(); it++)
    {
        sol += sum * it->second;
        sum += it->second;
    }
    cout << sol;
    return 0;
}
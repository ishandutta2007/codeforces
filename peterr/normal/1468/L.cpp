#include <bits/stdc++.h>

using namespace std;

const int BLOCK = 1E9;
const int MAXP = 1E6;
const int MAXN = 1000;
long long a[MAXN];
bool visited[MAXN];
int sieve[MAXP + 1];
vector<int> primes;
map<int, vector<long long>> freq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= MAXP; i++)
    {
        if (!sieve[i])
        {
            sieve[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int) primes.size() && primes[j] <= sieve[i] && primes[j] * i <= MAXP; j++)
            sieve[primes[j] * i] = primes[j];
    }
    //cout << primes.back() << endl;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        bool div = false;
        for (int p : primes)
        {
            if (a[i] % p == 0)
            {
                div = true;
                long long temp = a[i];
                while (temp % p == 0)
                    temp /= p;
                if (temp == 1)
                {
                    visited[i] = true;
                    freq[p].push_back(a[i]);
                }
                break;
            }
        }
        if (a[i] <= BLOCK && !div)
        {
            freq[(int) a[i]].push_back(a[i]);
            visited[i] = true;
        }
    }
    if (k == 1)
    {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] || a[i] <= BLOCK)
            continue;
        for (auto &it : freq)
        {
            if ((long long) it.first * it.first == a[i])
            {
                visited[i] = true;
                it.second.push_back(a[i]);
                //cout << "size " << it.second.size() << endl;
                break;
            }
        }
    }
    vector<pair<long long, vector<long long>>> extra;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;
        extra.push_back({a[i], vector<long long>()});
        long long temp = a[i];
        for (auto &it : freq)
        {
            if (it.second.size() < 2)
                continue;
            if (temp % it.first == 0)
            {
                extra.back().second.push_back(it.first);
                while (temp % it.first == 0)
                    temp /= it.first;
            }
        }
        if (temp != 1)
            extra.pop_back();
    }
    vector<long long> ans;
    for (auto &it : freq)
    {
        if (it.second.size() >= 2)
        {
            ans.push_back(it.second[0]);
            ans.push_back(it.second[1]);
        }
    }
    if ((int) ans.size() <= k)
    {
        for (auto &it : freq)
        {
            for (int i = 2; (int) ans.size() < k && i < (int) it.second.size(); i++)
            {
                ans.push_back(it.second[i]);
            }
        }
        for (int i = 0; (int) ans.size() < k && i < (int) extra.size(); i++)
        {
            ans.push_back(extra[i].first);
        }
        assert((int) ans.size() <= k);
        if ((int) ans.size() == k)
        {
            for (long long x : ans)
                cout << x << " ";
            cout << "\n";
        }
        else
            cout << "0\n";
    }
    else
    {
        if (k & 1)
        {
            ans.clear();
            bool found = false;
            long long chosen = 0;
            for (pair<long long, vector<long long>> pr : extra)
            {
                if ((int) pr.second.size() * 2 + 1 <= k)
                {
                    chosen = pr.first;
                    found = true;
                    ans.push_back(pr.first);
                    for (long long x : pr.second)
                    {
                        ans.push_back(freq[(int) x][0]);
                        ans.push_back(freq[(int) x][1]);
                    }
                    break;
                }
            }
            if (found)
            {
                for (auto &it : freq)
                {
                    if ((int) ans.size() == k)
                        break;
                    if (it.second.size() < 2 || chosen % it.first == 0)
                        continue;
                    ans.push_back(it.second[0]);
                    ans.push_back(it.second[1]);
                }
                for (long long x : ans)
                    cout << x << " ";
                cout << "\n";
            }
            else
            {
                for (auto &it : freq)
                {
                    if (it.second.size() < 2)
                        continue;
                    if (it.second.size() >= 3)
                    {
                        ans.push_back(it.second[0]);
                        ans.push_back(it.second[1]);
                        ans.push_back(it.second[2]);
                        break;
                    }
                }
                if (ans.empty())
                    cout << "0\n";
                else
                {
                    for (auto &it : freq)
                    {
                        if ((int) ans.size() == k)
                            break;
                        if (it.second.size() < 2 || it.second[0] == ans[0])
                            continue;
                        ans.push_back(it.second[0]);
                        ans.push_back(it.second[1]);
                    }
                    for (long long x : ans)
                        cout << x << " ";
                    cout << "\n";
                }
            }
        }
        else
        {
            for (int i = 0; i < k; i++)
                cout << ans[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}